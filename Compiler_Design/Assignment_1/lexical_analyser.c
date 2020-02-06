#include <stdio.h>
#include "myToken.h"

char tok_buffer[10];

int lexical_analyser(char ch){
    if(ch == ';') return TOK_SEMICOLON;
    else if(ch == 'i'){
	short i = 0;
	tok_buffer[i] = ch;
	while((ch = fgetc(fsource))!= ' ' ){
	    tok_buffer[++i] = ch;
	}
	tok_buffer[i] = '\0';
	if(strcmp(tok_buffer, "int") == 0){
	    return TOK_INT;
	}
	else{
	    return 
	}
    }
}

int main(){
    FILE* fsource = fopen("source.txt", "r");
    char ch = fgetc(fsource);
    while(!feof(fsource)){
	printf("%c ", ch);
	printf("%d\n", lexical_analyser(ch));
	ch = fgetc(fsource);
    }
}
