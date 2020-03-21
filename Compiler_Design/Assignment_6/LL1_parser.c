#include <stdio.h>
#include <string.h>

#define NO_RULES 3

typedef struct Productions{
    char LHS;
    char RHS[10];
    char first_set[3];
    char follow_set[3];
}Productions;

// ----- Global variable Section -----
char input_str[] = "n*n";
int parsing_table[3][3] = {
    {0, -1, -1},
    {-1, 1, 2},
    {3, -1, -1}
}
Productions productions[3];
char stack[10], state;
int top = 1;

void create_grammar(){
    // This function inserts the production rules for the while construct
    productions[0].LHS = 'S';
    strcpy(productions[0].RHS, "NE"); // w - While, b - Begin, e - End

    productions[1].LHS = 'E';
    strcpy(productions[1].RHS, "*NE|#");

    productions[2].LHS = 'N';
    strcpy(productions[2].RHS, "n");

}
void push(char ch){
    stack[top++] = ch;
    state = ch;
}
void LL1_parser(){

    while(count < strlen(input_str)){
        if(count == 0){
            // for starting symbol
            push('S');
        }
        else{

        }
    }
}
int main() {
    stack[0] = '$';
    create_grammar();
    LL1_parser();

}
