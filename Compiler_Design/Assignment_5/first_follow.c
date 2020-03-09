#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NO_RULES 3

void create_grammar(void);
void print_grammar(void);
int is_terminal(char);
void print_sets(void);

typedef struct Productions{
    char LHS;
    char RHS[10];
    char first_set[3];
    char follow_set[3];
}Productions;

Productions productions[4];

// char first_set[NO_RULES][NO_RULES];
// char follow_set[NO_RULES][NO_RULES];

void print_grammar(){
    printf("-----GRAMMAR-----\n\n");
    for (int i = 0; i < NO_RULES; ++i){
        printf("%c -> %s\n", productions[i].LHS, productions[i].RHS);
    }
}

int check_epsilon(char* str){
    for (int i = 0; i < strlen(str); ++i){
        if(str[i] == '#'){
            return 1;
        }
    }
    return 0;
}
void create_grammar(){
    // This function inserts the production rules for the while construct
    productions[0].LHS = 'S';
    strcpy(productions[0].RHS, "NE"); // w - While, b - Begin, e - End

    productions[1].LHS = 'E';
    strcpy(productions[1].RHS, "*NE|#");

    productions[2].LHS = 'N';
    strcpy(productions[2].RHS, "n");

}


int is_terminal(char ch){
    // if(!isupper(ch) || ch == '*' || ch == 'n'){
    //     return 1;
    // }
    // else{
    //     return 0;
    // }
    return (!isupper(ch) || ch == '*' || ch == 'n' || ch == '#' ? 1 : 0);
}

void find_first(){
    int id_first = 0;
    char current;
    for (short i = 0; i < NO_RULES; ++i){
        current = productions[i].LHS;
        for (short j=0; j < NO_RULES ; ++j){
            if (productions[j].LHS == current){
                if (is_terminal(productions[j].RHS[0])){
                    productions[j].first_set[id_first++] = productions[j].RHS[0];
                }
                if (check_epsilon(productions[j].RHS)){
                    productions[j].first_set[id_first++] = '#';
                }
                else {
                    for (short k = i; k < NO_RULES; ++k){
                        if (productions[k].LHS == productions[j].RHS[0]){
                            if (is_terminal(productions[k].RHS[0])){
                                productions[j].first_set[id_first++] = productions[k].RHS[0];
                            }
                        }
                    }
                }
            }
            id_first = 0;
            // productions[j].first_set[id_first++] = '\0';
        }
    }
}

int compare_productions(char current, char* str){
    for(short i = 0;i< strlen(str);i++){
        if(current == str[i]){
            return i;
        }
    }
    return 0;
}
void follow_set(){
    unsigned int id_follow = 0, idx=0;
    char current;
    productions[0].follow_set[id_follow] = '$';
    for (short i = 1; i < NO_RULES; ++i){
        current = productions[i].LHS;
        for (short j=0; j < NO_RULES ; ++j){
            if ((idx = compare_productions(current, productions[j].RHS))){
                if (productions[j].RHS[idx+1] == '\0'){
                    printf("-->%c", productions[i].LHS);
                    productions[i].follow_set[id_follow++] = productions[0].follow_set[0];
                }
                else {
                    
                }
            }
        }
    }
}
void print_sets(){
    printf("----First Sets----\n");
    for (int j = 0; j < NO_RULES; ++j){
        printf("%c { %s }\n", productions[j].LHS, productions[j].first_set);
    }
    printf("----Follow Sets----\n");
    for (int j = 0; j < NO_RULES; ++j){
        printf("%c { %s }\n", productions[j].LHS, productions[j].follow_set);
    }
}
int main(int argc, char const *argv[]){
    create_grammar();
    print_grammar();
    find_first();
    follow_set();
    print_sets();
    return 0;
}