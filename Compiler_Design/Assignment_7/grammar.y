%{
#include <stdio.h>
//#include "my_tokens.h"
//#include "lex.yy.c"
int yylex();
void yyerror(char*);
//extern int yyparse();
%}

%token TOK_WHILE TOK_L_PAREN TOK_R_PAREN TOK_L_CURLY TOK_R_CURLY TOK_ID TOK_GREATER TOK_ASSIGNMENT TOK_SEMICOLON TOK_PLUS
%left TOK_PLUS
%%

S : TOK_WHILE TOK_L_PAREN C TOK_R_PAREN TOK_L_CURLY X TOK_R_CURLY { printf("\nwhile\n"); }
  ;

C : E TOK_GREATER E  { printf("\ncondition");}
  ;

X : TOK_ID TOK_ASSIGNMENT E TOK_SEMICOLON {printf("\nASSignemnt %\n");}
  ;

E : E TOK_PLUS E {printf("\nplus\n");}
  | TOK_ID
  ;






%%
#include "lex.yy.c"
int main() {
printf("pars\n");
    yyparse();
    printf("parsing\n");

}
