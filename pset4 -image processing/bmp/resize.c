/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, bfold;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    
    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, biold;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    // making copies of infile's headers before updating them
    bfold = bf;
    biold = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // getting resize factor from command-line arguments
    int factor = atoi(argv[1]);
    
    // checking validity of said factor
    if (factor > 100 || factor < 1)
    {
        return 5;
    }
    
    // storing a copy of infile's padding
    int oldpadding =  (4 - (biold.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // updating height and width
    bi.biHeight *= factor;
    bi.biWidth *= factor;
    
    // determine new padding for scanlines 
    int newpadding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // updating image size and file size
    bi.biSizeImage = (bi.biWidth * sizeof(RGBTRIPLE) + newpadding) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + 54;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, bioldHeight = abs(biold.biHeight); i < bioldHeight; i++)
    {
        // interate to write factor times of each scanline
        for (int w = 0; w < factor; w++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < biold.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
    
                // read pixel from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                // write this pixel factor times in outfile
                for (int e = 0; e < factor; e++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            
            // move cursor back to start in infile
            if (w <= (factor - 2))
                fseek(inptr, -(sizeof(RGBTRIPLE) * biold.biWidth), SEEK_CUR);
            
            // add new padding to outfile
            for (int k = 0; k < newpadding; k++)
            {
                fputc(0x00, outptr);
            }
        }
        
        // skip over padding in infile
        fseek(inptr, oldpadding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
