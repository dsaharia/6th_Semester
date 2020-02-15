#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, const char* argv[]){
   if(argc < 2){
	perror("Usage: ./a.out <Filename>");
	exit(1);
   }
   //if(argv[1][strlen(argv[1]) - 3] == 'b'){
       FILE* file = fopen(argv[1], "rb");
       char buffer;
	int count = 0;
       while(feof(file) == 0){
	    fread(&buffer, sizeof(buffer), 1, file);
	    if(count % 16 == 0) {
		printf("\n");
		printf("%.7o ", count);
	    }
	    printf("%.3o ", buffer);
	    count++;
       }
       printf("\n");
       fclose(file);
   //}
}
