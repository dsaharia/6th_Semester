#include <stdio.h>
#include "myToken.h"
#include <ctype.h>
#include <string.h>

char tok_buffer[10];
FILE* fsrc;

void lexical_analyser(){
    char ch;
    while((ch = fgetc(fsrc)) != EOF){
		if(ch == ';') {
			printf("<;, TOK_SEMICOLON, %d>\n", TOK_SEMICOLON);
		}
		if(ch == '=') {
			tok_buffer[0] = ch;
			ch = fgetc(fsrc);
			tok_buffer[1] = ch;
			tok_buffer[2] = '\0';
			if(strcmp(tok_buffer, "==") == 0){
				printf("<==;, TOK_COMPARISON, %d>\n", TOK_ASSIGNMENT);
			}
			else{
				ungetc(ch, fsrc);
				printf("<=;, TOK_ASSIGNMENT, %d>\n", TOK_ASSIGNMENT);
			}
		}
		if(ch == '+') {
			tok_buffer[0] = ch;
			ch = fgetc(fsrc);
			tok_buffer[1] = ch;
			tok_buffer[2] = '\0';
			if(strcmp(tok_buffer, "++") == 0){
				printf("<++;, TOK_INCREMENT, %d>\n", TOK_ASSIGNMENT);
			}
			else if(strcmp(tok_buffer, "+=") == 0){
				printf("<+=;, TOK_ASSGN_INCR, %d>\n", TOK_ASSIGNMENT);
			}
			else{
				ungetc(ch, fsrc);
				printf("<+;, TOK_PLUS, %d>\n", TOK_PLUS);
			}
		}
		if(ch == '(') {
			printf("<(;, TOK_R_PAREN, %d>\n", TOK_R_PAREN);
		}
		if(ch == ')') {
			printf("<), TOK_L_PAREN, %d>\n", TOK_L_PAREN);
		}
		if(ch == '[') {
			printf("<[, TOK_R_SQBKT, %d>\n", TOK_R_SQBKT);
		}
		if(ch == ']') {
			printf("<], TOK_L_SQBKT, %d>\n", TOK_L_SQBKT);
		}
		if(ch == '{') {
			printf("<{;, TOK_R_CURLY, %d>\n", TOK_R_CURLY);
		}
		if(ch == '}') {
			printf("<}, TOK_L_CURLY, %d>\n", TOK_L_CURLY);
		}
		if(isalpha(ch)){
			// For Identfiers and keywords
			short i = 0;
			char ch2;
			tok_buffer[i] = ch;
			while(isalnum((ch2 = fgetc(fsrc))) || ch2 == '_'){
				tok_buffer[++i] = ch2;
			}
			tok_buffer[++i] = '\0';
			ungetc(ch2, fsrc);
			if(strcmp(tok_buffer, "int") == 0){
				printf("<int, TOK_INT, %d>\n", TOK_INT);
			}
			else if(strcmp(tok_buffer, "if") == 0){
				printf("<if, TOK_IF, %d>\n", TOK_IF);
			}
			else if(strcmp(tok_buffer, "else") == 0){
				printf("<else, TOK_ELSE, %d>\n", TOK_ELSE);
			}
			else{
				printf("<%s, TOK_ID, %d>\n", tok_buffer, TOK_ID);
			}
			//printf("TOK:%s\n", tok_buffer);
		}
		if(isdigit(ch)){
			short i = 0;
			tok_buffer[i] = ch;
			char ch2;
			while(isdigit((ch2 = fgetc(fsrc)))){
				tok_buffer[++i] = ch2;
			}
			ungetc(ch2, fsrc);
			tok_buffer[++i] = '\0';
			printf("<%s, TOK_NUM, %d>\n", tok_buffer, TOK_NUM);
		}
    }
}

int main(){
    fsrc = fopen("source.txt", "r");
    lexical_analyser();
    fclose(fsrc);
}
