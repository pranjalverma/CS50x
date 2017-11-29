/* Takes in plaintext (phrase, message etc.)
 * Encrypts it using Vigenere's Cipher.
 * Outputs ciphertext. */
 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Using main with command-line agruments.
int main(int argc, char* argv[])
{
    // Checking for correct format of input by user at command-line.
    if (argc != 2)
    {
        printf("Oi, you must type in at-least and only 1 command-line argument.\n");
        return 1;
    }
    
    // Checking validity of keyword provided.
    for(int w = 0, N = strlen(argv[1]); w < N; w++)
    {
        if (!isalpha(argv[1][w]))
        {
            printf("Keyword must compose entirely of alphabets, sire.\n");
            return 1;
        }
    }
    
    // Getting plaintext from user to encrypt.
    printf("Oh hai! What shall I encrypt for you?\n");
    char plaintext[100] = "\0";
    int check = scanf("%[^\n]%*c", plaintext);
        
    // Ensuring plaintext is valid.
    if (check != 0)
    {
        /* Using For-loop to iterate through each char of:
         * Plaintext
         * Keyword. */
        for(int i = 0, j = 0, n = strlen(plaintext), X = strlen(argv[1]); i < n; i++)
        {
            /* Handling alphabets:
             * Encrypting them.
             * Taking care of case sensitivity for:
             * * Plaintext
             * * Keyword */
            if (isalpha(plaintext[i]))
            {
                if (isupper(plaintext[i]))
                {
                    // Algorithm α: for getting ciphertext from plaintext.
                    if (isupper(argv[1][j]))
                    {
                        int ctalpha = ((plaintext[i] - 65) + (argv[1][j] - 65)) % 26;
                        int ctascii = ctalpha + 65;
                        printf("%c", ctascii);
                    }
                    
                    if (islower(argv[1][j]))
                    {
                        int ctalpha = ((plaintext[i] - 65) + (argv[1][j] - 97)) % 26;
                        int ctascii = ctalpha + 65;
                        printf("%c", ctascii);
                    }
                }
                    
                if (islower(plaintext[i]))
                {
                    // Algo α in action again!
                    if (isupper(argv[1][j]))
                    {
                        int ctalpha = ((plaintext[i] - 97) + (argv[1][j] - 65)) % 26;
                        int ctascii = ctalpha + 97;
                        printf("%c", ctascii);
                    }
                    
                    if (islower(argv[1][j]))
                    {
                        int ctalpha = ((plaintext[i] - 97) + (argv[1][j] - 97)) % 26;
                        int ctascii = ctalpha + 97;
                        printf("%c", ctascii);
                    }
                }
                
                /* Updating keyword iteration variable 'j', using modulo.
                 * Wraps around keyword when j == (X - 1).
                 * Update applied only for alphabets */
                j = (j + 1) % X;
            }
            
            // Handling non-alphabet chars: printing them as they are.
            if (!isalpha(plaintext[i]))
            {
                printf("%c", plaintext[i]);
            }
        }
        
        // Printing new line after encryption process.
        printf("\n");
    }
    
    return 0;
}