#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main(int argc, char const *argv[]){
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
        for(int i=1;i<strlen(buffer);i++){
	    if(count == field_number-1){
		int j = i;
		while(j < strlen(buffer) && buffer[j] != ' '){
		    printf("%c", buffer[j++]);
		}
		printf("\n");
		count = 0;
		break;
	    }
	    if(buffer[i] == ' ' && buffer[i-1]!= ' '){
		count++;
	    }
	}
	memset(buffer, 0x0, sizeof(buffer));
    }
    /*char ch = fgetc()
    while(feoef(finput) == 0){
	
    }*/
    return 0;
}
