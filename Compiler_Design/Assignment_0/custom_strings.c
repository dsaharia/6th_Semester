#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char* argv[]){
    if(argc < 2){
	perror("Usage: ./a.out <filename>\n");
	exit(1);
    }
    //if(argv[1][strlen(argv[1]) - 3] == 'b'){
	FILE* file = fopen(argv[1], "rb");
	char buffer;
	while(feof(file) == 0){
	    fread(&buffer, sizeof(buffer), 1, file);
	    //printf("%c ", buffer);
	    if(buffer >= ':' && buffer <= '}'){
		printf("%c ", buffer);
	    }
	    if(buffer == '\n') printf("\n");
	}
	fclose(file);
    //}
}
