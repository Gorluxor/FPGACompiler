#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codegen.h"
#include "symtab.h"
#include "ctype.h"

extern FILE *output;
int free_reg_num = 0;
char invalid_value[] = "???";
bool reg_taken[LAST_WORKING_REG] = {0};
// REGISTERS
char str[10];

typedef struct item {
        int value;
        int table_index;
} Items; 
Items inc_op[100];
int inc_counter = 0;

void post_op(int reg_index, bool increment){
	bool already = FALSE;		
	int index = 0;	
	for (int i = 0; i < inc_counter; i ++){
	  if (inc_op[i].table_index == reg_index){
	    already = TRUE; 
	    index = i;
	  }
	}
	if (already){
	  if (increment){
	    inc_op[index].value += 1;
	  }else{
	    inc_op[index].value -= 1; 
	  }
	}else{
	  index = inc_counter++;
	  if (inc_counter > 100)
	    err("Too many variables being incremented in one statement");
	  if (increment){
	    inc_op[index].value = 1;
          }else{
	    inc_op[index].value = -1;
	  }
	  inc_op[index].table_index = reg_index;
	}
}

void print_inc_dec() {
  for (int i = 0; i < inc_counter; i++) {
    if (inc_op[i].value != 0) {

      for (int j = 0; j < inc_op[i].value; j++) {
        if (inc_op[i].value > 0)
          gen_inc(1, inc_op[i].table_index);
        else
          gen_dec(1, inc_op[i].table_index);
      }
    }
  }
  inc_counter = 0;
}


int take_reg(void) {

  for (int i = 0; i < LAST_WORKING_REG; i++){
    if (reg_taken[i] != 1){
      reg_taken[i] = 1;			
      free_reg_num++;	
      return i;		
    }
  }
  err("Compiler error! No free registers!");
  exit(EXIT_FAILURE);  
  //if(free_reg_num > LAST_WORKING_REG) {
  //  err("Compiler error! No free registers!");
  //  exit(EXIT_FAILURE);
  // }
  // return free_reg_num++;
}

void free_reg(int a) {
  if(free_reg_num < 1) {
    err("Compiler error! No more registers to free!");
    exit(EXIT_FAILURE);
   }
   else{
     if (reg_taken[a] == 1){
	reg_taken[a] = 0;
	--free_reg_num;
	set_type(a, NO_TYPE);
    set_ispok(a, 0);
     }	
   }
}



// Ako je u pitanju indeks registra, oslobodi registar
void free_if_reg(int reg_index) {
  if(reg_index >= 0 && reg_index <= LAST_WORKING_REG)
    free_reg(reg_index);
}

// LABELS
void gen_sslab(char *str1, char *str2) {
  code("\n.%s%s:", str1, str2);
}

void gen_snlab(char *str, int num) {
  code("\n.%s%d:", str, num);
}

// SYMBOL
void print_symbol(int index) {
  if (index > -1) {
    if (get_kind(index) == VAR) // -n*4(%14)
      //code("-%d(%%14)", get_atr1(index) * 4);
      code("[r13 - %d]", get_atr1(index) * 4);  
    else
    if (get_kind(index) == PAR) // m*4(%14)
      //code("%d(%%14)", 4 + get_atr1(index) *4);
      code("[r13 + %d]", 4 + get_atr1(index) * 4); 
    else
    if (get_kind(index) == LIT)
      code("%s", get_name(index));
    else //function, reg
      code("%s", get_name(index));
  }
}
// prvo load iz zadate varijable, onda store u reg koristeci adresu iz loadovanje adrese
void print_symbol_address(int index, int reg) {
  if (index > -1) {
    code("\n");
    if (get_kind(index) == VAR) { // -n*4(%14)
      int val = get_atr1(index) * 4;
      code("\t\t\tMOV.w\tr%d,r13\t;POINTER", reg);
      //code("[r7 + %d]",  get_atr1(index) * 4 - 4); // changed from 2 - 2   
    } else {
      if (get_kind(index) == PAR) // m*4(%14)
      {
        int val = 4 + get_atr1(index) * 4;
        code("\t\t\tMOV.w\tr%d,r13\t;POINTER", reg);
        code("\t\t\tADD.w\tr%d,%d", reg, val);
        //code("[r7 - %d]", 4 +  get_atr1(index) *4); //  changed to 4 from 2
      } else {
        if (get_kind(index) == LIT)
          code("\t\t\tMOV.w\tr%d,%s", reg, get_name(index));
        else //function, reg
          code("\t\t\tMOV.w\tr%d,%s", reg, get_name(index));
      }
    }
  }
}
//Deprecated
void print_symbol_value(int index, int reg) {
  if (index > -1) {
    if (get_kind(index) == VAR) { // -n*4(%14)
      int val = get_atr1(index) * 4;
      code("\t\t\tMOV.w\tr%d,r13\t;POINTER", reg);
      code("\t\t\tADD.w\tr%d,%d", reg, val);
      //code("[r7 + %d]",  get_atr1(index) * 4 - 4); // changed from 2 - 2   
    } else {
      if (get_kind(index) == PAR) // m*4(%14)
      {
        int val = 4 + get_atr1(index) * 4;
        code("\t\t\tMOV.w\tr%d,r13\t;POINTER", reg);
        code("\t\t\tADD.w\tr%d,%d", reg, val);
        //code("[r7 - %d]", 4 +  get_atr1(index) *4); //  changed to 4 from 2
      } else {
        if (get_kind(index) == LIT)
          code("\t\t\tMOV.w\tr%d,%s", reg, get_name(index));
        else //function, reg
          code("\t\t\tMOV.w\tr%d,%s", reg, get_name(index));
      }
    }
  }

}

// OTHER

void gen_cmp_internal(int op1_index, int op2_index) {
  if (op1_index <= LAST_WORKING_REG)
     code("\n\t\t\tCMP.w \t");  
  else 
    {
    if (get_type(op1_index) == INT || get_type(op2_index) == INT)
        code("\n\t\t\tCMP.w \t");
    else if (get_type(op1_index) == SHORT || get_type(op2_index) == SHORT)
        code("\n\t\t\tCMP.s \t");
    else 
        code("\n\t\t\tCMP.b \t");
    }
 
  print_symbol(op1_index);
  code(",");
  print_symbol(op2_index);
  free_if_reg(op2_index);
  free_if_reg(op1_index);
}

void gen_cmp(int op1_index, int op2_index) {
  int k1 = get_kind(op1_index);
  int k2 = get_kind(op2_index);
  if (k1 & (VAR | PAR | LIT)) { // scenario LIT, __ or VAR|PAR, __
    int t1 = take_reg();
    gen_mov_code(op1_index, t1);
    gen_cmp_internal(t1, op2_index);
  } else {
    gen_cmp_internal(op1_index, op2_index);
  }
}

void gen_mov_code(int input_index, int output_index) {
  int t1 = get_kind(input_index);
  int t2 = get_kind(output_index);
 // for exp pointer
  if (t2 & REG && (t1 & (REG | LIT))) { // normal MOV
    code("\n\t\t\tMOV.w \t\t");
    print_symbol(output_index);
    code(",");
    print_symbol(input_index);
  } else if ((t2 & (VAR | PAR | GLB)) && (t1 & REG)) {
    code("\n\t\t\tST.w \t\t");

    print_symbol(output_index);
    code(",");
    print_symbol(input_index);
  } else if ((t2 & (VAR | PAR)) && (t1 & LIT)) { // Intermediate step because LIT can't be used in ST

    int temp_reg = take_reg();
    code("\n\t\t\tMOV.w \t\t");
    print_symbol(temp_reg);
    code(",");
    print_symbol(input_index);

    if (get_type(output_index) == BYTE)
      code("\n\t\t\tST.b \t\t");
    else if (get_type(output_index) == SHORT)
      code("\n\t\t\tST.s \t\t");
    else 
      code("\n\t\t\tST.w \t\t");
    print_symbol(output_index);
    code(",");
    print_symbol(temp_reg);
    free_reg(temp_reg);
  } else if ((t1 & (VAR | PAR)) && (t2 & REG)) {
    code("\n\t\t\t LD.w \t\t");
  
    print_symbol(output_index);
    code(",");
    print_symbol(input_index);
  } else if ((t1 & (VAR | PAR)) && (t2 & (VAR|PAR))){
	int temp_reg = take_reg();
    code("\n\t\t\tLD.w \t\t");
    print_symbol(temp_reg);
    code(",");
    print_symbol(input_index);

    if (get_type(output_index) == BYTE)
      code("\n\t\t\tST.b \t\t");
    else if (get_type(output_index) == SHORT)
      code("\n\t\t\tST.s \t\t");
    else 
      code("\n\t\t\tST.w \t\t");
    print_symbol(output_index);
    code(",");
    print_symbol(temp_reg);
    free_reg(temp_reg);
	}else {
	printf("k1:%d,k2:%d",t1,t2);
    code("\n\t\t\tMOV.w \t");
    print_symbol(output_index);
    code(",");
    print_symbol(input_index);
    printf("\nT1:%d,T2:%d\n", t1, t2);
    warn("Default mov generated");
  }
}

void gen_p_move(int input_index, int output_index){
	
  int t1 = get_kind(input_index);
  int t2 = get_kind(output_index);
  //set_ispok(output_index, get_ispok(input_index));
  int temp_reg = take_reg();
  if (t1 & LIT){
    code("\n\t\tMOV.w \t");
	print_symbol(temp_reg);
	code(",");
	print_symbol(input_index);
  }else if (t1 & (GLB|PAR|VAR)) {
	if (get_type(output_index) == BYTE)
      code("\n\t\tLD.b \t\t");
    else if (get_type(output_index) == SHORT)
      code("\n\t\tLD.s \t\t");
    else 
      code("\n\t\tLD.w \t\t");




	print_symbol(temp_reg);
    code(",");
	print_symbol(input_index);  //TODO Check if GLB can be used in this way
		
  	
	
  }
	int temp_reg2 = take_reg();
  // always *pok, thus memory, either PAR or VAR
  gen_mov_code(output_index,temp_reg2);

  if (get_type(output_index) == BYTE)
      code("\n\t\t\tST.b \t\t");
    else if (get_type(output_index) == SHORT)
      code("\n\t\t\tST.s \t\t");
    else 
      code("\n\t\t\tST.w \t\t");
  code("[r%d]",temp_reg2);
  code(",");
  print_symbol(temp_reg);
	free_if_reg(temp_reg);
	free_if_reg(temp_reg2);
}



void gen_mov(int input_index, int output_index) {
  //code("\n\t\t\tMOV \t");
  //print_symbol(output_index);	  
  //code(",");
  //print_symbol(input_index);
  gen_mov_code(input_index, output_index);

  //ako se smešta u registar, treba preneti tip 
  if (output_index >= 0 && output_index <= LAST_WORKING_REG){
    set_type(output_index, get_type(input_index));
	 set_ispok(output_index, get_ispok(input_index)); 
  }
  free_if_reg(input_index);
}

//Deprecated
char* get_arop_stmt_adv(int index, int arop, int type){
   if ((type < INT) || (type > SHORT) || (arop < 0) || (arop >= AROP_NUMBER)){
	printf("Deprecated");    
	return invalid_value;
   }else 
     { err("IND:%d,AROP:%d,T:%d", index, arop, type);
       if (index <= LAST_WORKING_REG){
         
         strcpy(str,arithmetic_operators[arop]);
         strcat(str,".w");
        return str;
       } else 
         return arithmetic_operators[arop + (type - 1) * AROP_NUMBER];
     }
}

/*int get_real_type(int type){
  int ltype;// INT 1, BYTE 2, SHORT 4
  if (type == BYTE)  ltype = 2; 
  else if (type == SHORT) ltype = 3; 
  else if (type == INT) ltype = 1; 
  else if (type == VOID) ltype = 4;
  else ltype = 0; 	
 return ltype;
}*/


char* get_arop_stmt(int arop, int type) {
  //type = get_real_type(type);
  if ((type < INT) || (type > SHORT) || (arop < 0) || (arop >= AROP_NUMBER)){
	err("Arop,STMT:%d,%d",arop,type);
	print_symtab();    
	return invalid_value;
  }else
    return arithmetic_operators[arop + (type - 1) * AROP_NUMBER];
}

int get_jump_idx(int relop, bool type) {
  return relop + ((type - 1) * RELOP_NUMBER);
}

char* get_jump_stmt(int jump_idx, bool opp) {
  if ((jump_idx < 0) || (jump_idx >= RELOP_NUMBER * 3)){
	err("Invalid jump %d, %d", jump_idx, opp);
	print_symtab();    
	return invalid_value;
  }else
    if(opp)
      return opp_jumps[jump_idx];
    else        
      return jumps[jump_idx];
} 

void gen_inc(int num, int idx) {
  //TODO special case for GLB
  //code("\n\t\t\tINC.s \t");
  if (get_type(idx) == BYTE) {
    code("\n\t\tINC.b \t");
  } else if (get_type(idx) == SHORT) {
    code("\n\t\tINC.s\t");
  } else {
    code("\n\t\tINC.w \t");
  }
  print_symbol(idx);
}

void gen_dec(int num, int idx) {
  //code("\n\t\t\tDEC.w \t");
  if (get_type(idx) == BYTE) {
    code("\n\t\t\tDEC.b \t");
  } else if (get_type(idx) == SHORT) {
    code("\n\t\t\tDEC.s\t");
  } else {
    code("\n\t\t\tDEC.w \t"); //TODO pointer
  }
  print_symbol(idx);
}






