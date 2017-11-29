/* Takes in plaintext (phrase, message etc.)
 * Encrypts it using Caesar's Cipher.
 * Outputs ciphertext. */
 
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Using main with command-line arguments.
int main(int argc, char* argv[])
{
    // Ensuring user only inputs one command-line argument.
    if (argc != 2)
    {
        printf("Thy must enter at-least and only 1 command-line argument.\n");
        return 1;
    }
    
    // Iterating through each char in argv[1] and verifying that it's a digit, as key can only be an int.
    for(int j = 0, N = strlen(argv[1]); j < N; j++)
    {
        if (!isdigit(argv[1][j]))
        {
            printf("Argument must be a valid integer, sire.\n");
            return 1;
        }
    }
    
    // Converting string to int to get key using atoi.
    int key = atoi(argv[1]);
    
    /* Checking validity of key.
     * 2147483622 is (2^31 - 26). */
    if (key < 0 || key >= 2147483622)
    {
        printf("Invalid key! Must be positive and less than (2^31 - 26).\n");
        return 1;
    }
    
    // Prompting user for input; obtained using GetString() from cs50 lib.
    printf("Hail, Caesar! What shall I encrypt for thy?\n");
    char* plaintext = GetString();
    
    // Verifying validity of obtained string.
    if (plaintext != NULL)
    {
        // Iterating through each char of plaintext.
        for(int i = 0, n = strlen(plaintext); i < n; i++)
        {
            // Handling alphabet chars, while taking care of case sensitivity.
            if (isalpha(plaintext[i]))
            {
                if (islower(plaintext[i]))
                {
                    // Algorithm α: for getting ciphertext from plaintext.
                    int ctalpha = (plaintext[i] - 97 + key) % 26;
                    int ctascii = ctalpha + 97;
                    printf("%c", ctascii);
                }
                
                if (isupper(plaintext[i]))
                {
                    // Algo α in action again!
                    int ctalpha = (plaintext[i] - 65 + key) % 26;
                    int ctascii = ctalpha + 65;
                    printf("%c", ctascii);
                }
            }
            // Handling non-alphabet chars.
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        // Printing new line after printing result.
        printf("\n");
    }
    return 0;
}