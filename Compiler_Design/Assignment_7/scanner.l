%{
#include <stdio.h>
#include "my_tokens.h"
%}

DIGIT [0-9]
ID [a-z][a-z0-9]*

%%

{DIGIT} { printf("-->%s\n", yytext); return TOK_NUM; }
{ID} {return TOK_ID; }
"while(c)" {return 101;}

%%

int main(){
    int token;
    while((token = yylex())){
	printf("TOK %d\n", token);
    }
}
