%{
//#include <stdio.h>
//#include "my_tokens.h"

//#include "grammar.tab.c"
%}

DIGIT [0-9]+
ID [a-z][a-z0-9]*

%%
"while" {return TOK_WHILE;}
{ID}    {return TOK_ID; }
"("     {return TOK_L_PAREN;} 
"="     {return TOK_ASSIGNMENT;}
")"     {return TOK_R_PAREN;}
">"     {return TOK_GREATER;}
"+"     {return TOK_PLUS;}
"{"     {return TOK_L_CURLY;}
"}"     {return TOK_R_CURLY;}
";"     {return TOK_SEMICOLON;}
[ \t\n]+ ;

%%
//int main(){
//    int token;
//    while((token = yylex())){
//	printf("TOK %d\n", token);
//    }
//}
//{DIGIT} { yylval = atoi(yytext); return TOK_NUM; }
