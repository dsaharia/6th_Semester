#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        perror("Usage: ./a.out <Filename>\n");
        exit(1);
    }
    int field_number;
    printf("Enter the Field-Number: \n");
    scanf("%d", &field_number);
    // Openning the File
    FILE* file = fopen(argv[1], "r");
    if(file == NULL){
        perror("File Opening Error:");
        exit(1);
    }
    return 0;
}