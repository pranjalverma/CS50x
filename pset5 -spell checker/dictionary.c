/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#include "dictionary.h"

// prerequisites
#define HASH_MAX 500
unsigned int mcount = 0;
unsigned int fcount = 0;
bool decide = false;
node* hashtable[HASH_MAX];

// prototype
int hash(const char* string);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // getting bucket and error checks
    int index = hash(word);
    if (hashtable[index] == NULL)
        return false; 
    
    // declaring buffer and variables to use
    char buffer[LENGTH + 1];
    int i, len;
    
    // handling case-sensitivity
    for (i = 0, len = strlen(word); i < len; i++)
    {    
        if (isalpha(word[i]))
            buffer[i] = tolower(word[i]);
        else
            buffer[i] = word[i];
    } 
    
    // assigning null terminator appropriately 
    buffer[len] = '\0'; 
    
    // traversing through nodes
    for (node* trav = hashtable[index]; 1; trav = trav -> next)
    {
        // spell-checking
        if (strcmp(buffer, trav -> word) == 0)
            return true;
        
        // exiting loop after checking the last node
        if (trav -> next == NULL)
            break; 
    }
    
    // nope!
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // initializing hashtable with NULLs
    for(int i = 0; i < HASH_MAX; i++)
        hashtable[i] = NULL;
    
    // opening given file and error checking
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
        return false;
    
    // declaring buffer
    char buffer[LENGTH + 1];
    
    // traversing through given dictionary word by word; stopping once EOF is hit
    for (fscanf(fp, "%s", buffer); !feof(fp); fscanf(fp, "%s", buffer))
    {
        // getting bucket
        int index = hash(buffer);
        
        // space management
        node* new_word = malloc(sizeof(node));
        mcount++;
        
        // node management
        strcpy(new_word -> word, buffer);
        new_word -> next = NULL;
        
        // inserting new node in linked list appropriately 
        if (hashtable[index] != NULL)
        {
            new_word -> next = hashtable[index];
            hashtable[index] = new_word;
        }
        else
        {
            hashtable[index] = new_word;
        }
    }
    
    // if EOF reached without error, flip 'decide' and return true; else false
    if (feof(fp))
    {
        fclose(fp);
        decide = true;
        return true;
    }
    else
    {
        fclose(fp);
        return false;
    }
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (decide)
        return mcount;
    else
        return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // iterate over array
    for (int i = 0; i < HASH_MAX; i++)
    {
        // cursor pointed to head of a list
        node* cursor = hashtable[i];
        
        // freeing each node in current list 
        while (cursor != NULL)
        {
            node* temp = cursor;
            cursor = cursor -> next;
            free(temp);
            
            fcount++;
        }
    }
    
    // if no memory leak, return true; else return false; voila! no need for valgrind here hah
    if (mcount == fcount)
        return true;
    else
        return false;
    
}

// hash function; self-made
int hash(const char* string)
{
    // seeding for deterministic nature
    srand(strlen(string));
    
    // getting index
    int len = strlen(string);
    len += rand();
    
    // ensuring index is within range
    while (len >= HASH_MAX)
        len = len % HASH_MAX;
        
    return len;
}