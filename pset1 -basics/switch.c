#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x  = GetInt();
    switch(x)
    {
        case 1:
            printf("Uno!\n");
            break;
        case 2:
            printf("Dos!\n");
            break;
        case 3:
            printf("Tre!\n");
            break;
        default:
            printf("sorry!\n");
    }
}

// Omitting "break;" creates a chain; going through all cases. Eg- Counting down from 5 to blast off! 