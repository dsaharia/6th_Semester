#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	    printf("%c:%o\n", buffer, buffer);
	    //sprintf(, "%o", buffer);
       }
       fclose(file);
   }
}
