#include <stdio.h>
#include <cs50.h>

int main(int argc, char* argv[])
{
    // Getting positional number of argument required by user.
    printf("Print which argument of argv[]?\n");
    int i = GetInt();
    
    // Printing result.
    printf("%s.\n", argv[i - 1]);
}