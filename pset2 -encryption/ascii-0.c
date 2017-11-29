#include <stdio.h>

int main(void)
{
    for(int i = 65; i < 65 + 26; i++)
    {
        // Type casting int i to char.
        printf("%d is %c.\n", i, (char) i); 
    }
}