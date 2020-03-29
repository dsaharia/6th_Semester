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
char input_str[] = "n*n*n$"; // enter the input string. Only supports * operator
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
    // This function inserts the production rules
    productions[0].LHS = 'S';
    strcpy(productions[0].RHS, "NE"); 

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
    // printf("%d %d\n", non_terminal, terminal);
    if(terminal == -1){
        flag = 1;
        return;
    }
    else if(non_terminal == -1){
        flag = 1;
        return;
    }
    int tab_data = parsing_table[non_terminal][terminal];
    // printf("-->%d\n", tab_data);
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
            break;
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
    if(input_str[count] == '$' && stack[top-1] == '$'){
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
    printf("\n---- Input Grammar ----\n\n");
    // printing the grammar
    for(int i=0;i < NO_RULES; i++){
        printf("%c -> %s\n", productions[i].LHS, productions[i].RHS);
    }
    printf("\n----LL(1) Parsing Table----\n\n");
    printf("\tn\t");
    printf("\t*\t");
    printf("\t$\t");
    printf("\n-----------------------------------------------\n");
    printf("\n");
    for(int row = 0;row< 3;row++){
        if(row == 0){
            printf("S\t");
        }
        else if(row == 1){
            printf("E\t");
        }
        else{
            printf("N\t");
        }
        for(int column = 0;column < 3;column ++){
            int tab_value = parsing_table[row][column];
            if(tab_value == 0){
                printf("%c->%s\t\t", productions[tab_value].LHS, productions[tab_value].RHS);
            }
            else if(tab_value == 1){
                printf("%c->%s\t\t", productions[tab_value].LHS, productions[tab_value].RHS);
            }
            else if(tab_value == 2){
                printf("%c->%s\t\t", productions[tab_value].LHS, productions[tab_value].RHS);
            }
            else if(tab_value == 3){
                printf("%c->%s\t\t", productions[tab_value].LHS, productions[tab_value].RHS);
            }
            else{
                printf("x\t\t");
            }
            
        }
        printf("\n\n-----------------------------------------------\n");
        printf("\n\n");
    }
    printf("Input String is: %s\n\n", input_str);
    printf("NOTE: # refers to Epsilon\n");
    printf("\n----Stack Contents----\n\n");
    LL1_parser();

}
