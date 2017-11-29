#include <stdio.h>
#include <cs50.h>

int GetPositiveInt(void);

int main(void)
{
    // Apply declared int.
    int x = GetPositiveInt();
    printf("Thanks for the positive integer, %d!\n", x);
}

// Define declared int.
int GetPositiveInt(void)
{
    int y;
    do
   {
       printf("Please give me a positive integer:\n");
       y = GetInt();
   }
    while (y <= 0);
    return y;
}