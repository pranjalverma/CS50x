/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define FATBLOCK 512

int main(void)
{
    // open card and check errors
    FILE* forensic_img = fopen("card.raw", "r");
    if (forensic_img == NULL)
    {
        printf("Couldn't open card..lo siento!\n");
        return 1;
    }
    
    // declare buffer and jpg pointer, initialised to NULL.
    uint8_t buffer[FATBLOCK];
    FILE* jpg = NULL;
    
    // jpg counter 
    int counter = 0;
    
    // code runs until eof
    do
    {
        // read data chunk into buffer
        fread(buffer, FATBLOCK, 1, forensic_img);
        
        /** checking for eof directly after fread() because of how feof() works
         * extra read occurs, but extra write doesn't */
        if (feof(forensic_img))
        {
            // close last jpg
            fclose(jpg);
    
            //close card
            fclose(forensic_img);
            
            return 0;
        }
        
        // start a new jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            // close any already open jpg
            if (counter != 0 && jpg != NULL)
                fclose(jpg);
            
            counter++; /* increment counter */
            
            // jpg name management
            char title[8];
            sprintf(title, "%03d.jpg", counter - 1);
            
            // open new jpg and write from buffer
            jpg = fopen(title, "w");
            fwrite(buffer, FATBLOCK, 1, jpg);
        }
        // already in a jpg; write from buffer
        else if (counter != 0)
        {
            fwrite(buffer, FATBLOCK, 1, jpg);
        }
    }
    while (1);
}