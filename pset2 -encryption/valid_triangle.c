#include <stdio.h>
#include <cs50.h>

// Function declaration.
bool valid_triangle(float sidea, float sideb, float sidec);

int main(void)
{
    // Code using functions.
}

// Function definition.
bool valid_triangle(float sidea, float sideb, float sidec)
{
    sidea = GetFloat();
    sideb = GetFloat();
    sidec = GetFloat();
    
    // Checking.
    if (sidea + sideb == sidec && sideb + sidec == sidea && sidec + sidea == sideb && sidea > 0 && sideb > 0 && sidec > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}