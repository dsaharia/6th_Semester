#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc < 2){
	perror("Usage: ./a.out <FILENAME>");
    }
    FILE* file = fopen(argv[1], "wb");
    if(file == NULL){
	perror("File Error");
	exit(1);
    }
    int total_students = 1;
    char name[21];
    int roll_number;

    while(total_students){
	printf("Enter name: \n");
	scanf("%s", name);
	printf("Enter Roll Number: \n");
	scanf("%d", &roll_number);
	fwrite(&name, sizeof(name), 1, file);
	fwrite(&roll_number, sizeof(roll_number), 1, file);
	total_students--;
    }
}
