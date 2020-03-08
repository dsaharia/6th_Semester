#include <stdio.h>
#include <string.h>
#include <ctype.h>

int C(); // For C productions
int S(); // For S Productions
int E(); // For E productions

int count = 0;
int flag = 0;
char input_string[] = "w (a>6) b a=a*8; e"; // Input String to parse

void recursive_parser()
{
    // Utility function to start the productions from S
    flag = S();
}

int S()
{
    // Starting State
    if(input_string[count++] == 'w')
    {
        if (input_string[count] == ' ')
        {
            count++; // ignore spaces
        }
        if(input_string[count++] == '(')
        {
            flag = C();
            if (flag == 0){
                if(input_string[count++] == ')')
                {
                    if (input_string[count++] == ' '){ ; }
                    if (input_string[count++] == 'b')
                    {
                        if (input_string[count++] == ' ')
                        flag = E();
                        // printf("Flag after E():%d\n", flag);
                        if(flag == 0){
                            if (input_string[count++] == ' ')
                            {
                                ;
                            }
                            if (input_string[count++] == 'e')
                            {
                                return 0; // accepted
                            }
                            else{
                                return 1;
                            }
                        }
                        else{
                            return 1;
                        }
                    }
                    else
                    {
                        return 1;
                    }
                }
                else
                {
                    return 1;
                }
            }
            else{
                return 1;
            }
        }
        else{
            return 1;
        }
    }
    else{
        return 1;
    }
}

int E()
{
    // Checking for Expression productions
    if (isalpha(input_string[count++]))
    {
        if (input_string[count++] == '=')
        {
            if (isalpha(input_string[count++]))
            {
                if (input_string[count++] == '*')
                {
                    if (isdigit(input_string[count++]))
                    {
                        if (input_string[count++] == ';')
                        {
                            return 0;
                        }
                    }
                }
            }
        }
        else
        {
            return 1;
        }
    }
    return 1;
}
int C()
{
    // Checks the productions for Conditionals
    if(isalpha(input_string[count++]))
    {
        if(input_string[count++] == '>')
        {
            if(isdigit(input_string[count++])){
                return 0;
            }
        }
        else return 1;
    }
    else return 1;
}
int main(int argc, char const *argv[])
{
    recursive_parser();
    // printf("Flag Final:%d\n", flag);
    printf("---The input String is: %s\n", input_string);
    printf("---Here w stands for While, b stands for Begin and e for End---\n");
    printf("---a is the Identifier---\n");
    if(flag == 0)
    {
        printf("Given String is VALID\n");
    }
    else
    {
        printf("Given String is INVALID\n");
    }
    return 0;
}