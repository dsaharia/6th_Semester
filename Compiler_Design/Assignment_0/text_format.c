#include <stdio.h>


int main(int argc, char* argv[]) {
    if(argc < 2){
	perror("Usage:./a.out <FileName>");
    }
    char name[21];
    int roll_number;
    int total_students = 10; // total records

    FILE* file = fopen(argv[1], "w");
    while(total_students){
	printf("Enter name: \n");
	scanf("%s", name);
	printf("Enter Roll Number: \n");
	scanf("%d", &roll_number);
	fputs(name, file);
	fputc(' ', file);
	fprintf(file, "%d\n", roll_number);
	total_students--;
    }
    fclose(file);

}
