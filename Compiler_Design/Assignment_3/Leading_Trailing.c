#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Rules{
    char LHS;
    char RHS[10];
}rules;

rules productions[4];
char check_leading_production(char);
char check_trailing_production(char);
void get_trailing_set();

void create_grammar(){
    // This function inserts the production rules for the while construct
    productions[0].LHS = 'A';
    strcpy(productions[0].RHS, "w(C)bSe"); // w - While, b - Begin, e - End

    productions[1].LHS = 'C';
    strcpy(productions[1].RHS, "id>n");

    productions[2].LHS = 'S';
    strcpy(productions[2].RHS, "E;");

    // productions[3].LHS = 'S';
    // strcpy(productions[3].RHS, "E;S");

    productions[3].LHS = 'E';
    strcpy(productions[3].RHS, "id=id*n");

}

void print_grammar(){
    printf("-----GRAMMAR-----\n\n");
    for (int i = 0; i < 4; ++i){
        printf("%c -> %s\n", productions[i].LHS, productions[i].RHS);
    }
}

int check_terminal(char ch){
    if(!isupper(ch) || 
        ch == '(' || 
        ch == ')' || 
        ch == ';' || 
        ch == '*' || 
        ch == '>' || 
        ch == '='){
        return 1;
    }
    else{
        return 0;
    }
}
char buffer;

void parse_grammar(){
    char current_str[10];
    int k = 0;
    char leading[10];
    char NT;
    for (int i = 0; i < 4; ++i){
        NT = productions[i].LHS;
        strcpy(current_str, productions[i].RHS);
        for(int j=0; j<strlen(current_str); j++){
            if(check_terminal(current_str[j])){
                printf("\nLeading (%c): {%c }", NT, current_str[j]);
                break;
            }
            else{
                buffer = current_str[j+1];
                printf("\nLeading (%c): {%c %c}", NT,check_leading_production(current_str[j]),buffer);
                break;
            }
        }
    }
    printf("\n");
    get_trailing_set();
}

void get_trailing_set(){
    // Calculates the trailing set
    char current_str[10];
    int k = 0;
    char leading[10];
    char NT;
    for (int i = 0; i < 4; ++i){
        NT = productions[i].LHS;
        strcpy(current_str, productions[i].RHS);
        for(int j=strlen(current_str)-1; j>=0; j--){
            if(check_terminal(current_str[j])){
                printf("\nTrailing (%c): {%c }", NT, current_str[j]);
                break;
            }
            else{
                buffer = current_str[j+1];
                printf("\nTrailing (%c): {%c %c}", NT,check_trailing_production(current_str[j]),buffer);
                break;
            }
        }
    }
    printf("\n");
}

char check_trailing_production(char current_NT){
    for (int i = 4; i < 0; --i){
        if(productions[i].LHS == current_NT){
            if(check_terminal(productions[i].RHS[0])){
                return productions[i].RHS[strlen(productions[i].RHS) - 1];
            }
            else{
                check_trailing_production(productions[i].RHS[strlen(productions[i].RHS) - 1]);
            }
        }
    }
}
char check_leading_production(char current_NT){
    for (int i = 0; i < 4; ++i){
        if(productions[i].LHS == current_NT){
            if(check_terminal(productions[i].RHS[0])){
                return productions[i].RHS[0];
            }
            else{
                check_leading_production(productions[i].RHS[0]);
            }
        }
    }
}
int main(){
    create_grammar();
    print_grammar();
    parse_grammar();
    printf("Here i stands for Id(Identifier) and n stands for Number.\n");
}