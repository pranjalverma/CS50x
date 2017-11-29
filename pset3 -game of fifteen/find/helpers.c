/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int start = 0;
    int end = n;
    while (start <= end)
    {
        int midpoint = (start + end) / 2;
        
        if (values[midpoint] == value) 
        {
            return true;
        }
        else if (value < values[midpoint])
        {
            end = midpoint - 1;
            search(value, &values[n], end - start);
        }
        else if (value > values[midpoint])
        {
            start = midpoint + 1;
            search(value, &values[n], end - start);
        }
    }
    
    return false;
}

/**
 * Sorts array of n values using Bubble Sort.
 */
void sort(int values[], int n)
{
    int swapcount = -1;
    for(int i = 0; swapcount != 0; i++)
    {
        swapcount = 0;
        for(int j = 0; j < n - 1; j++)
        {
            if (values[j + 1] < values[j])
            {
                int store = values[j];
                values[j] = values[j + 1];
                values[j + 1] = store;
                swapcount++;
            }
        }
    }
    return;
}
