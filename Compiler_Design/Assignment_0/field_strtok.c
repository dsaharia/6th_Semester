#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int main(int argc, char* argv[]){
    if (argc != 2){
        perror("Usage: ./a.out <Filename>\n");
        exit(1);
    }
    int field_number;
    char buffer[50];
    printf("Enter the Field-Number: \n");
    scanf("%d", &field_number);
    // Opening the File
    FILE* file = fopen(argv[1], "r");
    if(file == NULL){
        perror("File Opening Error:");
        exit(1);
    }
    int count = 0;
    while(fgets(buffer, MAX, file) != NULL){
	char* token = strtok(buffer, " ");
	while(token != NULL){
	    if(count == field_number-1 && (strcmp(token, " ")) != 0){
		printf("%s\n", token);
		count = 0;
		break;
	    }
	    count++;
	    token = strtok(NULL, " ");
	}
    }

}
