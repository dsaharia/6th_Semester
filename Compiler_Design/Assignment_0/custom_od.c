#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, const char* argv[]){
   if(argc < 2){
	perror("Usage: ./a.out <Filename>");
	exit(1);
   }
   if(argv[1][strlen(argv[1]) - 3] == 'b'){
       FILE* file = fopen(argv[1], "rb");
       char buffer;
       while(feof(file) == 0){
	    fread(&buffer, sizeof(buffer), 1, file);
	    //printf("%c:%o\n", buffer, buffer);
	    //int temp = atoi(&buffer);
	    if(buffer == '\0'){
		printf("\\0:%o\n", buffer);
	    }
	    else if(isdigit(buffer) != 0){
		printf("Num\n");
	    }
	    else{
		printf("%c:%o\n", buffer, buffer);
	    }
	    /*if(isdigit(buffer) != 0){
		printf("%d:%o\n", buffer, buffer);
	    }*/
       }
       fclose(file);
   }
}
