#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NO_RULES 4

typedef struct Productions{
    char LHS;
    char RHS[10];
    char first_set[3];
    char follow_set[3];
}Productions;
void print_stack(void);
void pop(void);

// ----- Global variable Section -----
char input_str[] = "n+n$";
int parsing_table[3][3] = {
        // n   *   $
    /*S*/ {0, -1, -1},
    /*E*/ {-1, 1, 2},
    /*N*/ {3, -1, -1}
};
Productions productions[4];
char stack[10], state;
int top = 1, count=0, flag = 0;

void create_grammar(){
    // This function inserts the production rules for the while construct
    productions[0].LHS = 'S';
    strcpy(productions[0].RHS, "NE"); // w - While, b - Begin, e - End

    productions[1].LHS = 'E';
    strcpy(productions[1].RHS, "*NE");

    productions[2].LHS = 'E';
    strcpy(productions[2].RHS, "#");

    productions[3].LHS = 'N';
    strcpy(productions[3].RHS, "n");

}
void push(char ch){
    if(ch == '#') return;
    stack[top++] = ch;
}

int match_top(char target){
    if(target == stack[top-1]){
        return 1;
    }
    else{
        return 0;
    }
}
int give_number(char target){
    if(isupper(target)){
        // is terminal
        if(target == 'S'){
            return 0;
        }
        else if(target == 'E'){
            return 1;
        }
        else if(target == 'N'){
            return 2;
        }
        else{
            return -1;
        }
    }
    else{
        // is a terminal
        if(target == 'n'){
            return 0;
        }
        else if(target == '*'){
            return 1;
        }
        else if(target == '$'){
            return 2;
        }
        else{
            return -1;
        }
    }
}
void action(){
    int non_terminal = give_number(stack[top-1]);
    int terminal = give_number(input_str[count]);
    printf("%d %d\n", non_terminal, terminal);
    if(terminal == -1){
        flag = 1;
        return;
    }
    else if(non_terminal == -1){
        flag = 1;
        return;
    }
    int tab_data = parsing_table[non_terminal][terminal];
    printf("-->%d\n", tab_data);
    if(tab_data == 0){
        pop();
        push('E');
        push('N');
    }
    else if(tab_data == 1){
        pop();
        push('E');
        push('N');
        push('*');
    }
    else if(tab_data == 2){
        pop();
        push('#');
    }
    else if(tab_data == 3){
        pop();
        push('n');
    }
    else{
        // error
        printf("ERROR\n");
        flag = 1;
    }
}
void LL1_parser(){
    push('S');
    while(stack[top-1] != '$'){
        if(flag){
            return;
        }
        if(match_top(input_str[count])){
            
            pop();
            count++;
        }
        else{
            action();
            print_stack();
            // break;
        }
    }
    if(input_str[count] == '$' && stack[top-1]){
        printf("String Accepted\n");
    }
    else{
        printf("Invalid String\n");
    }

    // }
}
void pop(){
    top--;
}
void print_stack(){
    for (int i = 0; i < top; ++i){
        printf(" %c ", stack[i]);
    }
    printf("\n");
}
int main() {
    stack[0] = '$';
    create_grammar();
    LL1_parser();

}
