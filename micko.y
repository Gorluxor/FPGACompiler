%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"
  #include <string.h>
  #define YYDEBUG 0
  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
  int lab_num = -1;
  int typeOf = 0;
  int pointerType = 0;
  int global = 1;
  FILE *output;
  int arg_counter = 0;
  int par_counter = 0;
  extern unsigned no_type_array[];
%}

%union {
  int i;
  char *s;
}

%token <i> _TYPE 
%token _IF
%token _ELSE
%token _RETURN
%token <s> _ID
%token <s> _INT_NUMBER
%token <s> _BYTE_NUMBER
%token _LPAREN
%token _RPAREN
%token _LBRACKET
%token _FOR
%token _RBRACKET
%token _ASSIGN
%token _SEMICOLON
%token <i> _AROP 
%token _ASTERIKS
%token <i> _RELOP
%token _INC
%token _DEC
%token _DDOT
%token _QMARK
%token _COMMA
%token _DO
%token _WHILE
%token _AMP
%token <s> _ASM

%type <i> arop type num_exp exp literal parameter parameter_list
%type <i> function_call argument argument_list rel_exp if_part 
%type <i> conditional_value conditional_operator increment decrement 

%right _INC
%right _DEC

%left _ASTERIKS

%nonassoc ONLY_IF
%nonassoc _ELSE

%start program
//%error-verbose
%%

program
  : 	
  {
    // CREATED TO JUMP TO MAIN
    code("\tBegin_INST:");
    code("\n\t\tMOV sp, 0xeeee");
    code("\n\t\tPUSH\t 0x0");

    code("\n\t\tCALL\t main"); // previous function doesnt exist
    code("\n\t\tHALT");	
  } 
  variable_list function_list
  {  
    int idx = lookup_symbol("main", FUN);
    if(idx == -1)
      err("undefined reference to 'main'");
    else 
      if(get_type(idx) != INT)
        warn("return type of 'main' is not int");
      }
  ;

asm
  : _ASM {code("\t%s",$1);} 
  ;

function_list
  : function 
  | function_list function
  | function_list asm
  ;

function
  : type _ID
      {
	global = 0; // its inside the function 
        fun_idx = lookup_symbol($2, FUN);
        if(fun_idx == -1)
          fun_idx = insert_symbol($2, FUN, $1, NO_ATR, no_type_array, pointerType); // pointerType for fun
        else 
          err("redefinition of function '%s'", $2);

        code("\n%s:", $2);

	code("\n\t\t\tPUSH\tr7"); 
	code("\n\t\t\tMOV \tr7,sp");      
      }
    _LPAREN parameter_list _RPAREN
      {
        par_counter = 0;
        set_atr1(fun_idx, $5);
        var_num = 0;
      }
    body
      {
         
	clear_symbols(fun_idx + 1);
	gen_sslab($2,"_exit");
	code("\n\t\t\tMOV \tsp,r7");
	code("\n\t\t\tPOP \tr7");
	code("\n\t\t\tRET");			
      }
  ;

type
  : _TYPE
        { 
          typeOf = $1;
	  pointerType = 0;
	  $$ = $1;
        }
  | _TYPE _ASTERIKS 
	{
	  typeOf = POINTER;
	  pointerType = $1;
	  $$ = typeOf;
	}
  ;

parameter_list
	: { $$ = 0;}
	| parameter { par_counter++; $$ = $1; }
	| parameter_list _COMMA parameter { par_counter = $1 + $3; $$ = $1 + $3;}
	;
parameter
  //: /* empty */
  //    { $$ = 0; }

  : type _ID
      {       
        insert_symbol($2, PAR, $1, 1, no_type_array, NO_ATR);
        set_atr2(fun_idx, par_counter, $1);
        $$ = 1;
      }
  ;

body
  : _LBRACKET variable_list
      {
       
        if(var_num)
	  code("\n\t\t\tADD\t\tsp, %d",4*var_num); // was 2 before push4
        gen_sslab(get_name(fun_idx), "_body");
      }
    statement_list _RBRACKET
  ;

variable_list
  : /* empty */ 
  | variable_list variable
  ;



variable_part
  : _ID 
        {
          if (global ==  0){
	    if(lookup_symbol($1, VAR|PAR) == -1){
	      if (typeOf == POINTER)
		insert_symbol($1, VAR, typeOf, ++var_num, no_type_array, pointerType);
	      else					
		insert_symbol($1, VAR, typeOf, ++var_num, no_type_array, NO_ATR);
	    }else 
		err("redefinition of '%s'", $1);		
          } else {
	    if (lookup_symbol($1, GLB) == -1){
		if (typeOf == POINTER)
		  insert_symbol($1, GLB, typeOf, NO_ATR, no_type_array, pointerType);
		else 
		  insert_symbol($1, GLB, typeOf, NO_ATR, no_type_array, NO_ATR);
	    }
		else
		  err("Redefinition of global varibale '%s'", $1);
        	// Generate Directives for global variables
	    code("\n%s", $1);
	    code("\n\t\t\t #res 2"); // TODO type check??	
       	  }
				 
	}
  | variable_part _COMMA _ID
	{
	  if (global == 0){
	    if(lookup_symbol($3, VAR|PAR) == -1){
		if (typeOf == POINTER)
		  insert_symbol($3, VAR, typeOf, ++var_num, no_type_array, pointerType);
		else					
		  insert_symbol($3, VAR, typeOf, ++var_num, no_type_array, NO_ATR);        	  
		}else 
		  err("redefinition of '%s'", $3);
		} else {
		  if (lookup_symbol($3, GLB) == -1){
		    if (typeOf == POINTER)
		      insert_symbol($3, GLB, typeOf, NO_ATR, no_type_array, pointerType);
		    else 
		      insert_symbol($3, GLB, typeOf, NO_ATR, no_type_array, NO_ATR);
		  }else
		      err("Redefinition of global varibale '%s'", $3);
		
	     // Generate Directives for global variables
	     code("\n%s", $3);
	     code("\n\t\t\t #res 2"); // TODO type check??		
          }
		
	}
  ;



variable
  : type variable_part _SEMICOLON
  ;




statement_list
  : /* empty */
  | statement_list statement { print_inc_dec(); }
  ;

statement
  : compound_statement
	| assignment_statement 
	| if_statement
	| return_statement
	| increment
	| decrement
	| do_loop  
	| while_loop
	| for_loop
	| asm 
	;

increment
	:  _ID _INC _SEMICOLON
	{
	  int idx = lookup_symbol($1, (VAR|PAR|GLB));
	  if (idx == -1){
	    err("invalid type for increment '%s'", $1);
          }
	  gen_inc(1,idx);		
	}
	;
decrement
	: _ID _DEC _SEMICOLON
	{
	  int idx = lookup_symbol($1, (VAR|PAR|GLB));
          if (idx == -1){
            err("invalid type for decrement '%s'", $1);
          }
	  gen_dec(1,idx);	
	}
	;



compound_statement
  : _LBRACKET statement_list _RBRACKET
  ;

do_loop 
  : _DO 
        { 
	  $<i>$ = ++lab_num;
	  gen_snlab("do", lab_num); 	 
	}
	statement _WHILE _LPAREN rel_exp _RPAREN _SEMICOLON
	{
	  code("\n\t\t\t%s\t.do%d",get_jump_stmt($6, FALSE),$<i>2);
	}
	;

while_loop
	: _WHILE 
	{
	  $<i>$ = ++lab_num;
	  gen_snlab("while", lab_num);
	}
	_LPAREN rel_exp 
	{
	  code("\n\t\t\t%s\t.exit%d",get_jump_stmt($4, TRUE),$<i>2);
	}		
	_RPAREN statement
	{
	  code("\n\t\t\tJ .while%d",$<i>2);
	  code("\n.exit%d:\t", $<i>2);
	}
	;

for_loop
	: _FOR _LPAREN assignment_statement 
	 {
	   $<i>$ = ++lab_num;
	   gen_snlab("for",lab_num);		
	 }
	 rel_exp _SEMICOLON left_part_assignment _RPAREN 
	 {
           code("\n\t\t\t%s\t.exit%d", get_jump_stmt($5, TRUE), $<i>4);
	 }
	 statement 
	 {
	   code("\n\t\t\tj\t.for%d",$<i>4);
	   code("\n.exit%d:",$<i>4);
	 }
	;


assignment_statement
  :   left_part_assignment _SEMICOLON
  ;

left_part_assignment
	: _ID _ASSIGN num_exp 
	{
          
	  int idx = lookup_symbol($1, (VAR|PAR|GLB));
	  if(idx == -1)
		err("invalid lvalue '%s' in assignment", $1);
	  else
          {
	    if (get_type(idx) != POINTER)
	      if (get_type($3) == POINTER && get_type(idx) == INT)
	        warn("Allocating Address into a integer variable!");
	    else				
	      if (get_type(idx) != get_type($3))
	        err("incompatible types in assignment, %d : %d", get_type(idx), get_type($3));
	  }
    	  gen_mov($3,idx);
	  code("\t\t;ASSIGN");
	}
	;

arop
  : _AROP { $$ = $1;}
  | _ASTERIKS { $$ = MUL; }

num_exp
  : exp 

  | num_exp arop exp
  {
    if (get_type($1) == POINTER || get_type($3) == POINTER){
      if (get_type($1) == POINTER) 
	set_type($1, INT);
      if (get_type($3) == POINTER)
	set_type($3, INT);			
      //warn("aritmehic operations with address??");					
      } else if(get_type($1) != get_type($3))
      	  err("invalid operands: arithmetic operation, %d : %d", get_type($1), get_type($3));
        int t1 = get_type($1);
	
	$$ = take_reg();
        set_type($$, t1);
	set_pok($$, get_pok($3)); // for pointer
	gen_mov_code($1,$$);

	code("\t;EXPRETION");
	code("\n\t\t\t%s\t\t", get_arop_stmt($2, t1));
		       
	
	print_symbol($$);
	code(",");
	print_symbol($3); 


	if($3 >= 0 && $3 <= LAST_WORKING_REG)
	  free_reg($3);
	if($1 >= 0 && $1 <= LAST_WORKING_REG)
	  free_reg($1);
      }
  | conditional_operator  
  ;




exp
  : literal

  | _ID
      {
        $$ = lookup_symbol($1, (VAR|PAR|GLB));
        if($$ == -1)
          err("'%s' undeclared", $1);
      }

  | function_call
     {
       $$ = take_reg();
       gen_mov(FUN_REG, $$);
       code("\t\t;FUN_REG");
     }
  
  | _LPAREN num_exp _RPAREN
     { $$ = $2; }
  | _ID _INC 
        { // INC
	$$ = lookup_symbol($1, (VAR|PAR|GLB));
	if ($$ == -1)
	  err("'%s' undeclared", $1);
        
         post_op($$, TRUE);
        
	}
	| _ID _DEC 
	{ // DEC
	  $$ = lookup_symbol($1, (VAR|PAR|GLB));
	  if ($$ == -1)
	    err("'%s' undeclared", $1);

          post_op($$, FALSE);
	}
	| _ASTERIKS exp 
        {
	  int idx = $2;
	  if (idx == -1)
	    err("Can't find Expression in symbol table");
	  if (get_pok($2) == 0)
	    err("Trying to dereference something that isn't a pointer");
	  if (get_pok($2) == 0)
	    err("Error while trying to find what the variable is pointing at");
	  //printf("Before move! %d",idx);
	  print_symtab();	
	
	  $$ = take_reg();
	
	  //printf("\n\t\tTHISTYPE:%d for var:%d\n\n reg:%d", get_type(get_pok(idx)),idx,$$);
	  gen_mov(idx,$$);
	  //printf("\n\t\tTHISTYPE:%d\n\n", get_type(get_pok(idx)));
	  set_type($$,get_type(get_pok(idx)));
	  if (get_type(get_pok(idx)) == BYTE){
	    code("\n\t\t\tLD.b\t r%d,[r%d]", $$,$$);
		
	  } else {
	    code("\n\t\t\tLD\t r%d,[r%d]", $$,$$); // for pointer as well
		
	  }
	  print_symtab();	
	}

	| _AMP exp {
	  int idx = $2;
	  if (idx == -1){
	    err("Can't find Expression in symbol table");
	  }
	  if (lookup_symbol(get_name(idx), (VAR|PAR|GLB)) == -1){
	    err("Referencing invalid type");
	  }

	  $$ = take_reg();
	  set_pok($$, idx);
	  set_type($$,POINTER);
	  print_symtab();
	  //printf("\n\n\t%d:%d\n\n",$$,idx);
	  print_symbol_address(idx, $$);
		
	}
  ;

literal
  : _INT_NUMBER
      { $$ = insert_literal($1, INT); }

  | _BYTE_NUMBER
      { $$ = insert_literal($1, BYTE); }
  ;



function_call
  : _ID 
      {
       
        fcall_idx = lookup_symbol($1, FUN);
        if(fcall_idx == -1)
          err("'%s' is not a function", $1);
        print_symtab();
      }
    _LPAREN argument_list _RPAREN
      {
        arg_counter = 0;
        if(get_atr1(fcall_idx) != $4)
          err("wrong number of arguments");
        code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
        if($4 > 0)
	  code("\n\t\t\tSUB \tsp, %d", $4 * 2);
        set_type(FUN_REG, get_type(fcall_idx));
        $$ = FUN_REG;
      }
  ;

argument_list
	: argument { $$ = $1;}
	| argument_list _COMMA argument { $$ = $1 + $3;}
	;
argument
  : /* empty */
    { $$ = 0; arg_counter = 0;}

  | num_exp
    { 

      if (get_atr2(fcall_idx,arg_counter) != get_type($1))
        err("incompatible type for argument");      
      //if(get_atr2(fcall_idx) != get_type($1))
      arg_counter++;
      free_if_reg($1);
      if (get_type($1) != POINTER){
        code("\n\t\t\tPUSH\t");
        print_symbol($1);
      }else { // check
        int a = take_reg();
        gen_mov($1, a);
        code("\n\t\t\tPUSH\t");
        print_symbol(a);
        free_if_reg(a);
      }
      $$ = 1;
    }
  ;

if_statement
  : if_part %prec ONLY_IF
      { gen_snlab("exit", $1); }

  | if_part _ELSE statement
      { gen_snlab("exit", $1);}
  ;

conditional_operator
	: _LPAREN rel_exp _RPAREN _QMARK conditional_value _DDOT conditional_value
	{
	  ++lab_num;
	  gen_snlab("ter", lab_num);
	  if(get_type($5)!=get_type($7))
	    err("Conditional values not the same type");
	  int reg=take_reg();
	  code("\n\t\t\t%s\t.false%d",get_jump_stmt($2, TRUE),lab_num);

	  gen_snlab("true", lab_num);
	  gen_mov($5, reg);
	  code("\n\t\t\tJ \t.exit%d", lab_num);
 	  gen_snlab("false", lab_num);
	  gen_mov($7, reg);
	  gen_snlab("exit",lab_num);
	  $$ = reg;
	}
	;

conditional_value
	: literal { $$ = $1;}
	| _ID 
	{
	  $$ = lookup_symbol($1, (VAR|PAR|GLB));
	  if ($$ == -1)
	    err("'%s' undeclared", $1);
	}
	;

if_part
  : _IF _LPAREN
      {
        $<i>$ = ++lab_num;
        gen_snlab("if", lab_num);
      }
    rel_exp
      { 
	code("\n\t\t\t%s\t.false%d", 
        get_jump_stmt($4, TRUE),$<i>3);
        gen_snlab("true", $<i>3);
      }
    _RPAREN statement
      {

	code("\n\t\t\tJ \t.exit%d", $<i>3);        
	gen_snlab("false", $<i>3);
        $$ = $<i>3;
      }
  ;

rel_exp
  : num_exp _RELOP num_exp
      {
	if (get_type($1) != POINTER && get_type($3) != POINTER)
          if(get_type($1) != get_type($3))
    	   err("invalid operands: relational operator");
        $$ = $2 + ((get_type($1) - 1) * RELOP_NUMBER);
        gen_cmp($1, $3);
      }
  ;

return_statement
  : _RETURN num_exp _SEMICOLON
      {
        if(get_type(fun_idx) != get_type($2))
          err("incompatible types in return");
        gen_mov($2, FUN_REG);       
	code("\n\t\t\tJ \t.%s_exit", get_name(fun_idx));          
      }
  ;

%%

int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}


void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
	
  #if YYDEBUG == 1
  extern int yydebug;
  yydebug = 1;
  #endif

  int synerr;
  init_symtab();
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  print_symtab();

  clear_symtab();
  fclose(output);
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count) {
    remove("output.asm");
    printf("\n%d error(s).\n", error_count);
  }

  if(synerr)
    return -1;
  else
    return error_count;
}

