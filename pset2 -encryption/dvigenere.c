/* Takes in ciphertext (encrypted message)
 * Decrypts it using Vigenere's Cipher.
 * Outputs plaintext. */
 
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
    
    // Getting ciphertext from user to decrypt.
    printf("Oh hai! What shall I decrypt for you?\n");
    char ciphertext[100] = "\0";
    int check = scanf("%[^\n]%*c", ciphertext); /* pressing enter ensures input of \n */
        
    // Ensuring ciphertext is valid.
    if (check != 0)
    {
        /* Using For-loop to iterate through each char of:
         * Ciphertext
         * Keyword. */
        for(int i = 0, j = 0, n = strlen(ciphertext), X = strlen(argv[1]); i < n; i++)
        {
            /* Handling alphabets:
             * Decrypting them.
             * Taking care of case sensitivity for:
             * * Ciphertext
             * * Keyword */
            if (isalpha(ciphertext[i]))
            {
                if (isupper(ciphertext[i]))
                {
                    // Algorithm !α: for getting plaintext from ciphertext.
                    if (isupper(argv[1][j]))
                    {
                        int ptalpha = ((ciphertext[i] - 65) - (argv[1][j] - 65)) % 26;
                        
                        if (ptalpha < 0)    /* handling negative ptalpha because of C99 */
                            ptalpha += 26;
                            
                        int ptascii = ptalpha + 65;
                        printf("%c", ptascii);
                    }
                    
                    if (islower(argv[1][j]))
                    {
                        int ptalpha = ((ciphertext[i] - 65) - (argv[1][j] - 97)) % 26;
                        
                        if (ptalpha < 0)
                            ptalpha += 26;
                            
                        int ptascii = ptalpha + 65;
                        printf("%c", ptascii);
                    }
                }
                    
                if (islower(ciphertext[i]))
                {
                    // Algo !α in action again!
                    if (isupper(argv[1][j]))
                    {
                        int ptalpha = ((ciphertext[i] - 97) - (argv[1][j] - 65)) % 26;
                        
                        if (ptalpha < 0)
                            ptalpha += 26;
                            
                        int ptascii = ptalpha + 97;
                        printf("%c", ptascii);
                    }
                    
                    if (islower(argv[1][j]))
                    {
                        int ptalpha = ((ciphertext[i] - 97) - (argv[1][j] - 97)) % 26;
                        
                        if (ptalpha < 0)
                            ptalpha += 26;
                        
                        int ptascii = ptalpha + 97;
                        printf("%c", ptascii);
                    }
                }
                
                /* Updating keyword iteration variable 'j', using modulo.
                 * Wraps around keyword when j == (X - 1).
                 * Update applied only for alphabets */
                j = (j + 1) % X;
            }
            
            // Handling non-alphabet chars: printing them as they are.
            if (!isalpha(ciphertext[i]))
            {
                printf("%c", ciphertext[i]);
            }
        }
        
        // Printing new line after decryption process.
        printf("\n");
    }
    
    return 0;
}