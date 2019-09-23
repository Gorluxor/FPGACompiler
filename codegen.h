#ifndef CODEGEN_H
#define CODEGEN_H

#include "defs.h"

// funkcije za zauzimanje, oslobadjanje registra
int  take_reg(void);
void free_reg(int);
// oslobadja ako jeste indeks registra
void free_if_reg(int reg_index); 

// generise labelu koja se sastoji od 2 stringa 
// npr: @main_exit
void gen_sslab(char *str1, char *str2);

// generise labelu koja se sastoji 
// od jednog stringa i jednog broja npr: @if0
void gen_snlab(char *str, int num);

void post_op(int reg_index, bool increment);
void print_inc_dec();

// ispisuje simbol (u odgovarajucem obliku) 
// koji se nalazi na datom indeksu u tabeli simbola
void print_symbol(int index);
void print_symbol_address(int index, int reg);
// generise CMP naredbu, parametri su indeksi operanada u TS-a 
void gen_cmp(int operand1_index, int operand2_index);

// generise MOV naredbu, parametri su indeksi operanada u TS-a 
void gen_mov(int input_index, int output_index);

// generate code depending on type (REG,LIT,PAR,VAR => MOV, ST or LD) 
void gen_mov_code(int input_index, int output_index);

//vraca string aritmeticke naredbe
char* get_arop_stmt(int arop, int type);
char* get_arop_stmt_adv(int index, int arop, int type);


//vraca operaciju uslovnog skoka
char* get_jump_stmt(int jump, bool opp);
//vraca indeks u nizu stringova naredbi skokova
int get_jump_idx(int relop, bool type);

void gen_inc(int num, int operand);
void gen_dec(int num, int operand);


#endif
