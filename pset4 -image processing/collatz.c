/**Gets positive int from user.
 * Applies Collatz conjecture.
 * Prints out no. of steps performed.
 **/

#include <stdio.h>

int collatz(int m);

int main(void)
{
    printf("Enter a positive integer:\n");
    
    // Checking validity of input.
    int n;
    do
    {
        scanf("%d", &n);
    }
    while(n <=0);

    // Printing result using collatz().
    printf("%d\n", collatz(n));
}

// Collatz function implementation using recursion.
int collatz(int m)
{
    if (m == 1) /* base case */
    {
        return 0;
    }
    else if (m % 2) /* odd recursive case */
    {
        return (1 + collatz(3 * m + 1));
    }
    else /* even recursive case */ 
    {
        return (1 + collatz(m / 2));
    }
}