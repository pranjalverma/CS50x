#include <stdio.h>
#include <cs50.h>
#include <math.h> 

int main(void)
{
    // Get floating point value from user and round off.
    float due;
    do
    {
        printf("Hello, whats your due amount?\n");
        due = GetFloat();
    }
    while(due <= 0);
    float x = due * 100;
    int cents = roundf(x);
    
    // Coin dispenser algorithm.
    int quarters = 0;
    while(cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    
    int dimes = 0;
    while(cents >= 10)
    {
        dimes++;
        cents = cents - 10;
    }
    
    int nickels = 0;
    while(cents >= 5)
    {
        nickels++;
        cents = cents - 5;
    }
    
    int pennies = 0;
    while(cents >= 1)
    {
        pennies++;
        cents = cents - 1;
    }
    
    // Print result.
    printf("%d\n", quarters + dimes + nickels + pennies);
}