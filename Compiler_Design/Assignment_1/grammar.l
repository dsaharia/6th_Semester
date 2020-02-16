%{
// Definitions
#include <stdio.h>
#include "myToken.h"
%}

%%
[\n \t] {continue;}
"int" {printf("<TOK_INT, %d>\n", TOK_INT);}
"if" {printf("<TOK_IF, %d>\n", TOK_IF);}
"=" {printf("<TOK_ASSIGNMENT, %d>\n", TOK_ASSIGNMENT);}
"==" {printf("<TOK_COMPARISON, %d>\n", TOK_COMPARISON);}
"+" {printf("<TOK_PLUS, %d>\n", TOK_PLUS);}
"++" {printf("<TOK_INCREMENT, %d>\n", TOK_INCREMENT);}
"+=" {printf("<TOK_ASSGN_INCR, %d>\n", TOK_ASSGN_INCR);}
"else" {printf("<TOK_ELSE, %d>\n", TOK_ELSE);}
"[" {printf("<TOK_R_SQBKT, %d>\n", TOK_R_SQBKT);}
"]" {printf("<TOK_L_SQBKT, %d>\n", TOK_L_SQBKT);}
"(" {printf("<TOK_R_PAREN, %d>\n", TOK_R_PAREN);}
")" {printf("<TOK_L_PAREN, %d>\n", TOK_L_PAREN);}
"{" {printf("<TOK_R_CURLY, %d>\n", TOK_R_CURLY);}
"}" {printf("<TOK_L_CURLY, %d>\n", TOK_L_CURLY);}
";" {printf("<TOK_SEMICOLON, %d>\n", TOK_SEMICOLON);}
"return" {printf("<TOK_RETURN, %d>\n", TOK_RETURN);}
[0-9]+ {printf("<%s, TOK_NUM, %d>\n", yytext, TOK_NUM);}
[a-zA-Z][a-z_A-z_0-9]* {printf("<%s, TOK_ID, %d>\n", yytext, TOK_ID);}

%%

int main(){
    int val;
    yylex();
}
