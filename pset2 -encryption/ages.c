#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Getting valid no. of people in room.
    int n;
    do
    {
        printf("How many people in the room?\n");
        n = GetInt();
    }
    while(n < 1);
    
    // Declaring array of floating point values; ages.
    float ages[n];
    
    // Getting valid ages.
    for(int i = 0; i < n; i++)
    {
        do
        {
            printf("Age of person number %d:", i + 1);
            ages[i] = GetFloat();
        }
        while(ages[i] < 1);
    }
    
    // Getting no. of years to operate on.
    float years;
    do
    {
        printf("Fast-forward to how many years?\n");
        years = GetFloat();
    }
    while(years < 0);
    
    
    // Computing resulting ages.
    for(int j = 0; j < n; j++)
    {
        printf("Age of person number %d will be %.2f years after %.2f year(s).\n", j + 1, ages[j] + years, years);
    }
    
    return 0;
}