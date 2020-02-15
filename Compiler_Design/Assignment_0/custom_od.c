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
	int count = 0;
       while(feof(file) == 0){
	    fread(&buffer, sizeof(buffer), 1, file);
	    //printf("%c:%o\n", buffer, buffer);
	    //int temp = atoi(&buffer);
	    if(buffer == '\0'){
		printf(" \\0:%.3o", buffer);
		if(count % 16 == 0) printf("%d\n", count);
		count++;
	    }
	    else{
		if(buffer >= '0' && buffer <= '9'){
		    if(count % 16 == 0) printf("\n");
		    printf("%d:%.3o", buffer, buffer);
		}
		else if(buffer == '\f') {
		    printf(" \\f:%.3o", buffer);
		    if(count % 16 == 0) printf("\n");
		}
		else{
		    if(count % 16 == 0) printf("\n");
		    printf(" %c:%.3o", buffer, buffer);
		}
		count++;
	    }
       }
       fclose(file);
   }
}
