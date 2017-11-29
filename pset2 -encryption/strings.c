#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = GetString();
    
    // Checking for valid string.
    if (s != NULL)
    {
        // Iterating over each char and printing it in new line.
        for(int i = 0, n = strlen(s); i < n; i++)
        {
            printf("%c\n", s[i]);
        }
    }
}