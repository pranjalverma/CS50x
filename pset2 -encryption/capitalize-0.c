#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // Get string from user.
    string s = GetString();
    
    // Loop for dealing with each char of s.
    for(int i = 0, n = strlen(s); i < n; i++)
    {
        // Selection and capitalization.
        // Every string can be treated as an array or chars.
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - ('a' - 'A'));
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    
    // Print new line after result.
    printf("\n");
    
    return 0;
}