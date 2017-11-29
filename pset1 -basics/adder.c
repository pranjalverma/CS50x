#include <stdio.h> 
#include <cs50.h>

int main(void)
{
    // Get integers from user.
    printf("Please give me an integer\n");
    int x = GetInt();
    
    printf("Please give me another integer\n");
    int y = GetInt();
    
    // Add and print result.
    printf("The sum of %d and %d is %d.\n", x, y, x+y);
}