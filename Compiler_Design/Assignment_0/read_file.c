#include <stdio.h>
#include <stdlib.h>

#define MAX 50
int main()
{
	int count = 1;
	char buffer[MAX];
	FILE* finput = fopen("test.txt", "r");
	while(fgets(buffer, MAX, finput) != NULL){
		printf("%d %s", count++, buffer);
	}
}
