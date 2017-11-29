#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get integer from user.
    printf("Please give me an integer:\n");
    int x = GetInt();
    
    // Analyze and print result.
    if (x>0)
    {
        printf("%d is a positive integer.\n", x);
    }
    else if (x==0)
    {
        printf("%d is neither positive nor negetive.\n", x);
    }
    else
    {
        printf("%d is a negetive integer\n", x);
    }
}