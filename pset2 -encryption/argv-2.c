#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Loop nest for printing every char of everycommant-line argument.
    for(int i = 0; i < argc; i++)
    {
        for(int j = 0, n = strlen(argv[i]); j < n; j++)
        {
            printf("%c.\n", argv[i][j]);
        }
        
        // Printing a space after each string.
        printf(" \n");
    }
}