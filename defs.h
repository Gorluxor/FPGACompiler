#ifndef DEFS_H
#define DEFS_H

#define bool int
#define TRUE  1
#define FALSE 0

#define SYMBOL_TABLE_LENGTH   64
#define NO_ATR                 0
#define LAST_WORKING_REG       5
#define FUN_REG                6 
#define CHAR_BUFFER_LENGTH   128
extern char char_buffer[CHAR_BUFFER_LENGTH];

extern int out_lin;
//pomocni makroi za ispis
extern void warning(char *s);
extern int yyerror(char *s);
#define err(args...)  sprintf(char_buffer, args), \
                      yyerror(char_buffer)
#define warn(args...) sprintf(char_buffer, args), \
                      warning(char_buffer)
#define code(args...) ({fprintf(output, args); if (++out_lin > 2000) err("Too many output lines"), exit(1); })

//tipovi podataka
enum types { NO_TYPE, INT, BYTE, INT_POINTER, BYTE_POINTER, VOID, VOID_POINTER };

//vrste simbola (moze ih biti maksimalno 32)
enum kinds { NO_KIND = 0x1, REG = 0x2, LIT = 0x4, 
             FUN = 0x8, VAR = 0x10, PAR = 0x20, GLB = 0x40 };

//konstante arithmetickih operatora
enum arops { ADD, SUB, MUL, DIV, AROP_NUMBER };
//stringovi za generisanje aritmetickih naredbi
static char *arithmetic_operators[] = { "ADD", "SUB", "MUL", "DIV",
                                        "ADD.b", "SUB.b", "MUL.b", "DIV.b" };

//konstante relacionih operatora
enum relops { LT, GT, LE, GE, EQ, NE, RELOP_NUMBER };
//stringovi za JMP narebu
static char* jumps[]={"JNP ", "JG ", "JSE ", "JP ", "JZ ", "JNZ ",
                      "JNP ", "JG ", "JSE ", "JP ", "JZ ", "JNZ " };


static char* opp_jumps[]={"JP ", "JSE ", "JG ", "JNP", "JNZ ", "JZ ",
                          "JP ", "JSE ", "JG ", "JNP", "JNZ ", "JZ "};
#endif
