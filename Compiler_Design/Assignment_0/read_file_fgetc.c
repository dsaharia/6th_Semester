#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* finput = fopen("test.txt", "r");
    char ch;
    int count=1;
    ch = fgetc(finput);
    printf("%d ", count);
    while(feof(finput)==0)
    {
        printf("%c", ch);
        if(ch == '\n')
        {
            printf("%d ",++count);
        }
        ch = fgetc(finput);
    }
}
