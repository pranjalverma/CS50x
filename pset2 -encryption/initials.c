/* Takes name from user.
 * Outputs initials in uppercase letters. */
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Get name from user.
    char* name = GetString();
    
    // Checking validity of name.
    if (name != NULL)
    {
        // Declaring a bool variable as a marker for whitespaces.
        bool marker = true;
        
        // For-loop to iterate through every char in name.
        for(int i = 0, n = strlen(name); i < n; i++)
        {
            // Conditions for printing initials from name, using marker.
            if (name[i] != ' ' && marker == true)
            {
                printf("%c", toupper(name[i]));
                marker = false;
            }
            
            if (name[i] == ' ')
            {
                marker = true;
            }
        }
        
        // Printing new line after result.
        printf("\n");
    }
}