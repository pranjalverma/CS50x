#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt and get height from user.
    int height;
    do 
    {
        printf("What'll be the height of your half-pyramid?\n");
        height = GetInt();
    }
    while(height > 23 || height < 0);
    
    // Loop for rows.
    for(int i = 0; i < height; i++)
    {
        // Loop for spaces.
        for(int space = 0; space < height - i - 1; space++)
        {
            printf(" ");
        }
        
        // Loop for hashes. 
        for(int hash = 0; hash < i + 2; hash++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}