#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get temperature value from user and convert.
    printf("Give me a temperature in F:\n");
    float f = GetFloat();
    
    float c = 5.0 / 9.0 * (f - 32.0);
    
    // Print result.
    printf("%.2f is the temperature in C.\n", c);
}