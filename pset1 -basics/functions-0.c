#include <stdio.h>
#include <cs50.h>

void PrintName(string x);

int main(void)
{
    // Get name from user and apply void.
    printf("Your name?\n");
    string s = GetString();
    
    PrintName(s);
}

// Define void.
void PrintName(string x)
{
    printf("hello, %s!\n", x);
}