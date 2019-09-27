%option noyywrap yylineno
%{
   #include <string.h>
   #include "micko.tab.h"
   #include "defs.h"
   #include "limits.h"
   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>
   extern YYSTYPE yylval;
   extern int first_line;
// int asm_count = 0;
%}

%x ASM
%x MCOMMENT
%%

"asm{"               {  BEGIN(ASM); first_line = 1; /*freopen("output.bin", "a", stdout);*/ }

<ASM>^[^}]*          { yylval.s = strdup(yytext); return _ASM; }

<ASM>"}" 	     { BEGIN(INITIAL); }



[ \t\n]+             { /* skip */ }

"int"                { yylval.i = INT;  return _TYPE; }
"char"               { yylval.i = BYTE; return _TYPE; }
"void"		     { yylval.i = VOID; return _TYPE; }
"short"               { yylval.i = SHORT; return _TYPE; }

"if"                 { return _IF; }
"else"               { return _ELSE; }
"return"             { return _RETURN; }
"for"		     { return _FOR; }
"do"		     { return _DO; }
"while"		     { return _WHILE; }

"++"		     { return _INC; }
"--"		     { return _DEC; }
","		     { return _COMMA; }

"("                  { return _LPAREN; }
")"                  { return _RPAREN; }
"{"                  { return _LBRACKET; }
"}"                  { return _RBRACKET; }
";"                  { return _SEMICOLON; }
"="                  { return _ASSIGN; }
"?"		     { return _QMARK; }
":"		     { return _DDOT; } 

"&"		     { return _AMP; }
"+"                  { yylval.i = ADD; return _AROP; }
"-"                  { yylval.i = SUB; return _AROP; }
"*"		     { return _ASTERIKS; } //{ yylval.i = MUL; return _AROP; }
"/"		     { yylval.i = DIV; return _AROP; }


"<"                  { yylval.i = LT; return _RELOP; }
">"                  { yylval.i = GT; return _RELOP; }
"<="                 { yylval.i = LE; return _RELOP; }
">="                 { yylval.i = GE; return _RELOP; }
"=="                 { yylval.i = EQ; return _RELOP; }
"!="                 { yylval.i = NE; return _RELOP; }

[a-zA-Z][a-zA-Z0-9]* { yylval.s = strdup(yytext); 
                       return _ID; }


 /*[+-]?[0-9]{1,10}     { 
			long conv = atoi(yytext[0] == '+' ? strdup(&(yytext[1])) : strdup(yytext));
			if (conv > INT_MAX || conv < INT_MIN){
			  err("Number out of range");
			}else if (conv > SHRT_MAX || conv < SHRT_MIN){
			  yylval.s = yytext[0] == '+' ? strdup(&(yytext[1])) : strdup(yytext);
			  return _INT_NUMBER;
			}else if (conv > CHAR_MAX || conv < CHAR_MIN){
			  yylval.s = yytext[0] == '+' ? strdup(&(yytext[1])) : strdup(yytext);
			  return _SHORT_NUMBER;
			} else {
			  yylval.s = yytext[0] == '+' ? strdup(&(yytext[1])) : strdup(yytext);
			  return _BYTE_NUMBER;
			}

		     } */

[+-]?[0-9]{1,10}      { 
		       if (yytext[0] == '+'){
	  		 yylval.s = strdup(&(yytext[1]));  // escaping + sign
		       }else{
			 yylval.s = strdup(yytext); 
		       }
                       return _INT_NUMBER;
		     }


[+-]?[0-9]{1,6}[s]      { 
		       if (yytext[0] == '+'){
	  		 yylval.s = strdup(&(yytext[1]));  // escaping + sign
		       }else{
			 yylval.s = strdup(yytext); 
		       }
                       return _SHORT_NUMBER;
		     }
[+-]?[0-9]{1,3}[bB]  { if (yytext[0] == '+'){
			 yylval.s = strdup(&(yytext[1])); // escaping + sign
		       } else{
			 yylval.s = strdup(yytext); 
		       }
                       yylval.s[yyleng-1] = 0;
                       return _BYTE_NUMBER;
					 }

\/\/.*               { /* skip */ }
.                    { printf("line %d: LEXICAL ERROR on char %c\n", yylineno, *yytext);}
%%
