#include <stdio.h>
#include <cs50.h>

// Using arguments for main.
int main(int argc, char* argv[])
{
    // Printing each command-line argument.
    for(int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
}