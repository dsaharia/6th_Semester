%{
#include <stdio.h>
#include <string.h>

int yylex();
void yyerror(char*);

char tmp[5];
char lbl[5];
int count = 0;
int line = 100;

void newTemp(){
    sprintf(tmp, "T%d", count++);
}
void newLabel(){
    sprintf(lbl, "L%d", count++);
}
%}

%union{
    int bool_value;
    char* op;
    struct id_val{
	int val;
	char* id;
	char* code;
	char* addr;
	char* True;
	char* False;
    }id_val;
}


%token TOK_WHILE
%token TOK_L_PAREN TOK_R_PAREN TOK_L_CURLY TOK_R_CURLY 
%token TOK_ID TOK_GREATER TOK_ASSIGNMENT TOK_SEMICOLON TOK_PLUS
%left TOK_PLUS
%nonassoc TOK_GREATER TOK_ASSIGNMENT
%type <op> TOK_PLUS TOK_ASSIGNMENT
%type <id_val> TOK_ID E C X
%%

S : TOK_WHILE TOK_L_PAREN C TOK_R_PAREN TOK_L_CURLY X TOK_R_CURLY { 
                                                                    char temp_code[100];
								    sprintf(temp_code, "\nBEGIN: %s\n%s: %s\nGOTO: BEGIN\nGOTO: %s",
								    $3.code, $3.True, $6.code, $3.False);
                                                                    printf("%s\n", temp_code); printf("L-:%d\n", line); }
  ;

C : E TOK_GREATER E  { 
                       newLabel();
                       $$.True = strdup(lbl);
		       newLabel();
		       line++;
		       $$.False = strdup(lbl);
                       char temp_code[80];
		       sprintf(temp_code, "%d %s %s \n if %s > %s GOTO %s \n GOTO %s", line++,  $1.code, $3.code, $1.addr, $3.addr, $$.True, $$.False);
		       $$.code = temp_code;}
                       //printf("--> %s\n", temp_code);}
  ;

X : TOK_ID TOK_ASSIGNMENT E TOK_SEMICOLON {
                                            char temp_code[25];
                                            sprintf(temp_code, "%s \n %s = %s", $3.code, $1.id, $3.addr);
					    $$.code = temp_code;
					    line++;
                                            printf("\n-->%s", $$.code);}
  ;

E : E TOK_PLUS E {
                   char temp_code[50];
		   newTemp();
		   $$.addr = strdup(tmp);
		   sprintf(temp_code, "%s %s \n %s = %s + %s", $1.code, $3.code, $$.addr, $1.addr, $3.addr);
                   $$.code = temp_code; 
		   line++;
		   //printf("len: %d\n", strlen(temp_code));
		   printf("-> %s\n", temp_code); memset(temp_code, 0x0, 50);}
  | TOK_ID  {$$.addr = $1.id; $$.code = ""}
  ;






%%
#include "lex.yy.c"
int main() {
    printf("Enter the while statement: \n");
    yyparse();
    printf("parsing\n");

}
