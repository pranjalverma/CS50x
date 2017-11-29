#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Get shower time from user.
    printf("How many minutes do you shower?\n");
    int m = GetInt();
    
    // Calulate no. of bottles and print result.
    int b = ( 12 * m );
    printf("You utilize %d bottles of water per bath!\n", b);
}