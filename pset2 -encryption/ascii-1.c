#include <stdio.h>

int main(void)
{
    // Loop for printing ascii.
    // Under the hood, 'c' is just a number, so we can manipulate it as such.
    for(char c = 'A'; c <= 'Z'; c++)
    {
        printf("%d is %c.\n", (int) c, c);
    }
}