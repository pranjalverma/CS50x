#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include<ctype.h>

int main(void)
{
    // Get string from user.
    string s = GetString();
    
    // Loop for dealing with each char of s.
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        // Selection and capitalization.
        printf("%c", toupper(s[i]));
    }
    
    // Print new line after result.
    printf("\n");
    
    return 0;
}