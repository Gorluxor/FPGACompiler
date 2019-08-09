#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codegen.h"
#include "symtab.h"


extern FILE *output;
int free_reg_num = 0;
char invalid_value[] = "???";
bool reg_taken[LAST_WORKING_REG] = {0};
// REGISTERS

int take_reg(void) {

  for (int i = 0; i < LAST_WORKING_REG; i++)
	{
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
  if(index > -1) {
    if(get_kind(index) == VAR) // -n*4(%14)
      //code("-%d(%%14)", get_atr1(index) * 4);
		code("[r7 + %d]",  get_atr1(index) * 4 - 4); // changed from 2 - 2   
	else 
      if(get_kind(index) == PAR) // m*4(%14)
        //code("%d(%%14)", 4 + get_atr1(index) *4);
        code("[r7 - %d]", 4 +  get_atr1(index) *4); // diff char types TODO, changed to 4 from 2
	  else
        if(get_kind(index) == LIT)
          code("%s", get_name(index));
        else //function, reg
          code("%s", get_name(index));
  }
}

// OTHER

void gen_cmp_internal(int op1_index, int op2_index){
	if (get_type(op1_index) == INT || get_type(op2_index) == INT)
		//warn("Compare generated for INT even though one of them is BYTE type")
		code("\n\t\t\tCMP \t"); // IF ONE OF THEM IS INT, check as INT
  else
	  code("\n\t\t\tCMP.b \t");
  print_symbol(op1_index);
  code(",");
  print_symbol(op2_index);
  free_if_reg(op2_index);
  free_if_reg(op1_index);
}

void gen_cmp(int op1_index, int op2_index) {
	int k1 = get_kind(op1_index);
	int k2 = get_kind(op2_index);
	if (k1 & (VAR|PAR|LIT)){ // scenario LIT, __ or VAR|PAR, __
		int t1 = take_reg();
		gen_mov_code(op1_index,t1);
		gen_cmp_internal(t1, op2_index);
	}else {
		gen_cmp_internal(op1_index, op2_index);
	}
}

void gen_mov_code(int input_index, int output_index){
	int t1 = get_kind(input_index);
	int t2 = get_kind(output_index);

	if (t2 & REG && (t1 & (REG|LIT))){ // normal MOV
			code("\n\t\t\tMOV \t\t");
			print_symbol(output_index);	  
			code(",");
			print_symbol(input_index);
	}else if ((t2 & (VAR|PAR|GLB)) && (t1 & REG)){
			if (get_type(input_index) == BYTE)
				code("\n\t\t\tST.b \t\t");
			else			
				code("\n\t\t\tST \t\t");
			print_symbol(output_index);
			code(",");
			print_symbol(input_index);
	}else if ((t2 & (VAR|PAR)) && (t1 & LIT)){ // Intermediate step because LIT can't be used in ST
			
			int temp_reg = take_reg();
			code("\n\t\t\tMOV \t\t");			
			print_symbol(temp_reg);
			code(",");
			print_symbol(input_index);
			
			if (get_type(output_index) == BYTE)
				code("\n\t\t\tST.b \t\t");
			else
				code("\n\t\t\tST \t\t");
			print_symbol(output_index);
			code(",");			
			print_symbol(temp_reg);
			free_reg(temp_reg);
	}else if ((t1 & (VAR|PAR)) && (t2 & REG)){
			if (get_type(input_index) == BYTE)
				code("\n\t\t\tLD.b \t\t");
			else
				code("\n\t\t\tLD \t\t");
			print_symbol(output_index);
			code(",");
			print_symbol(input_index);
	}else {
			code("\n\t\t\tMOV \t");
			print_symbol(output_index);	  
			code(",");
			print_symbol(input_index);
			printf("\nT1:%d,T2:%d\n", t1,t2 );			
			warn("Default mov generated");
			

	}


}



void gen_mov(int input_index, int output_index) {
  //code("\n\t\t\tMOV \t");
  //print_symbol(output_index);	  
  //code(",");
	//print_symbol(input_index);
 	gen_mov_code(input_index, output_index);
  

  //ako se smešta u registar, treba preneti tip 
  if(output_index >= 0 && output_index <= LAST_WORKING_REG)
    set_type(output_index, get_type(input_index));
  free_if_reg(input_index);
}


char* get_arop_stmt(int arop, int type) {
  if ((type < INT) || (type > BYTE) || (arop < 0) || (arop >= AROP_NUMBER))
    return invalid_value;
  else
    return arithmetic_operators[arop + (type - 1) * AROP_NUMBER];
}

int get_jump_idx(int relop, bool type) {
  return relop + ((type - 1) * RELOP_NUMBER);
}

char* get_jump_stmt(int jump_idx, bool opp) {
  if ((jump_idx < 0) || (jump_idx >= RELOP_NUMBER * 2))
    return invalid_value;
  else
    if(opp)
      return opp_jumps[jump_idx];
    else        
      return jumps[jump_idx];
} 

void gen_inc(int num, int idx){
	//TODO special case for GLB
	if (get_type(idx) == INT){
		code("\n\t\tINC \t");		
	} else if (get_type(idx) == BYTE) {
		code("\n\t\tINC.b\t");	
	}else {
		code("\n\t\tINC \t");
	}
	print_symbol(idx);	
}


void gen_dec(int num, int idx){
	if (get_type(idx) == INT){
		code("\n\t\tDEC \t");		
	} else if (get_type(idx) == BYTE) {
		code("\n\t\tDEC.b\t");	
	} else if (get_type(idx) == POINTER){
		code("\n\t\tDEC \t");	//TODO pointer
	}	
	print_symbol(idx);	
}
