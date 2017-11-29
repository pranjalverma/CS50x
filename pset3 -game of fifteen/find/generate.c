/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Checks for valid command-line arguments.
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Converting string argv[1] to int value.
    int n = atoi(argv[1]);

    /** 
     * Get seed using srand48. 
     * If both n and s are provided
     * use n; use s, by converting from string to int value.
     * else, 
     * use n; s is assigned current time in seconds since Epoch.
     */
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    /** 
     * Print n pseudorandomly generated numbers.
     * Typecasting to integer because drand48 returns a double.
     */
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}