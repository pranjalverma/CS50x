/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

//global variables
int blankx; 
int blanky;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }
    
    // greet user with instructions
    greet();

    // initialize the board
    init();
    
    // Getting initial position of blankspace.
    blankx = d - 1;
    blanky = d - 1;

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    if (d % 2 == 0) /* swap case */
    {
        // Iterate through array and assign.
        for(int i = 0; i < d; i++)
        {
            for(int j = 0; j < d; j++)
            {
                board[i][j] = (d * (d - i)) - j - 1;
            }
        }
        
        // Anology to bubble sort for swaping. 
        int swap = board[d - 1][d - 2];
        board[d - 1][d - 2] = board[d - 1][d - 3];
        board[d - 1][d - 3] = swap;
    }
    else /* !swap case */
    {
        // Iteration and assignment. 
        for(int i = 0; i < d; i++)
        {
            for(int j = 0; j < d; j++)
            {
                board[i][j] = (d * (d - i)) - j - 1;
            }
        }
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // Iterate through array and print number.
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            if (board[i][j] > 0)
            {
                printf("%2d  ", board[i][j]); /* limit to 2 digit ints */
            }
            if (board[i][j] == 0) /* replace 0 with blank */
            {
                printf(" _  ");
            }
        }
        printf("\n\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // Get coordinates of tile.
    int tilex = NULL;
    int tiley = NULL;
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            if (board[i][j] == tile)
            {
                tiley = i;
                tilex = j;
            }
        }
        
        /** Check validity of tile; 
         * if valid, swap with blank; 
         * else, return false. **/
        if ((tiley == blanky && tilex == blankx - 1) || (tiley == blanky && tilex  == blankx + 1)
            || (tiley == blanky - 1 && tilex == blankx) || (tiley == blanky + 1 && tilex == blankx))
        {
            board[tiley][tilex] = 0; 
            board[blanky][blankx] = tile;
            blanky = tiley; /* Get new coordinates of blankspace */
            blankx = tilex;
            return true;
        }    
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    /** Check for winning config.;
     * if present, return true;
     * else, return false **/
    int checker = 1;
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            if (i == d - 1 && j == d - 1)
            {
                checker = 0;
            }
            
            if (board[i][j] != checker)
            {
                return false;
            }
            checker++;
        }
    }
    return true;
}