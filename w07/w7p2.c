/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)


Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAXIMUM_PATH_LENGTH 70
#define MINIMUM_PATH_LENGTH 10
#define MAXIMUM_LIVES 10
#define MINIMUM_LIVES 1
#define MULTIPLE 5
struct PlayerInformation {
    int lives;
    char playersymbole;
    int Count;
    int History[MAXIMUM_PATH_LENGTH];
};
struct GameInformation {
    int pathlenght;
    int moves;
    int BOMBPlacement[MAXIMUM_PATH_LENGTH];
    int TREASUREPlacement[MAXIMUM_PATH_LENGTH];
};

int main()
{
    int N, I, K;

    struct PlayerInformation P;    //P=Player
    struct GameInformation G;      //G=Game
    int movesRemaining, livesRemaining, movePosition = MAXIMUM_PATH_LENGTH + 1;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &P.playersymbole);
    do {
        printf("Set the number of lives: ");
        scanf("%d", &P.lives);

        if (P.lives < MINIMUM_LIVES || P.lives > MAXIMUM_LIVES)
        {
            printf("     Must be between %d and %d!\n", MINIMUM_LIVES, MAXIMUM_LIVES);

        }
    } while (P.lives < MINIMUM_LIVES || P.lives > MAXIMUM_LIVES);

    printf("Player configuration set-up is complete\n");
    printf("\n");

    printf("GAME Configuration\n");
    printf("------------------\n");

    do {
        printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE, MINIMUM_PATH_LENGTH, MAXIMUM_PATH_LENGTH);
        scanf("%d", &G.pathlenght);
        if ((G.pathlenght< MINIMUM_PATH_LENGTH || G.pathlenght > MAXIMUM_PATH_LENGTH) || (G.pathlenght % MULTIPLE != 0))
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while ((G.pathlenght < MINIMUM_PATH_LENGTH || G.pathlenght> MAXIMUM_PATH_LENGTH) || (G.pathlenght % MULTIPLE != 0));

    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &G.moves);
        if (G.moves < P.lives || G.moves > (int) (0.75 * G.pathlenght))
        {
            printf("    Value must be between %d and %d\n", P.lives, (int)(0.75 * G.pathlenght));
        }
    } while (G.moves < P.lives || G.moves >(int) (0.75 * G.pathlenght));
    printf("\n");

    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 20 to set!\n");
    for (N = 0; N < G.pathlenght; N+= 5)
    {
        printf("   Positions [%2d-%2d]: ", N + 1, N + 5);
        scanf("%d %d %d %d %d", &G.BOMBPlacement[N], &G.BOMBPlacement[N + 1], &G.BOMBPlacement[N + 2], &G.BOMBPlacement[N + 3], &G.BOMBPlacement[N + 4]);
    }
    printf("BOMB placement set\n");
    printf("\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 20 to set!\n");


    for (N = 0; N < G.pathlenght; N+= 5)
    {
        printf("   Positions [%2d-%2d]: ", N+ 1, N + 5);
        scanf("%d %d %d %d %d", &G.TREASUREPlacement[N], &G.TREASUREPlacement[N + 1], &G.TREASUREPlacement[N + 2], &G.TREASUREPlacement[N + 3], &G.TREASUREPlacement[N+ 4]);
    }

    printf("TREASURE placement set\n");
    printf("\n");

    printf("GAME configuration set-up is complete...\n");
    printf("\n");


    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");


    printf("Player:\n");
    printf("   Symbol     : %c\n", P.playersymbole);
    printf("   Lives      : %d\n", P.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");

    // Game Details
    printf("Game:\n");
    printf("   Path Length: %d\n", G.pathlenght);

    // Bombs
    printf("   Bombs      : ");
    // Displaying bombs array
    for (I = 0; I < G.pathlenght; I++)
    {
        printf("%d", G.BOMBPlacement[I]);
    }
    printf("\n");


    printf("   Treasure   : ");

    for (K = 0; K < G.pathlenght; K++)
    {
        printf("%d",G.TREASUREPlacement[K]);
    }
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    
    
    movesRemaining = G.moves;
    livesRemaining = P.lives;
    P.Count = 0;
    int vCount = 0;

    char currentPosition[MAXIMUM_PATH_LENGTH];
    char positionItem[MAXIMUM_PATH_LENGTH];

    for (I = 0; I < G.pathlenght; I++) {
        P.History[I] = 0;
    }

    for (K = 0; K < G.pathlenght; K++) {
        positionItem[K] = '-';
    }

    for (K = 0; K < G.pathlenght; K++) {
        currentPosition[K] = ' ';
    }

    // Printing the table
    do {
        // First Line
        for (K = 0; K < G.pathlenght; K++) {
            if (currentPosition[K] == 'V') {
                vCount++;
            }
        }
        if (vCount == 0) {
            printf("\n");
        }
        else {
            printf("  ");
            for (K = 0; K < G.pathlenght; K++) {
                if (currentPosition[K] == 'V') {
                    printf("%c\n", currentPosition[K]);
                    break;
                }
                else {
                    printf("%c", currentPosition[K]);
                }
            }
        }

        // Tracking current position requires the previous pointer to disappear
        for (K = 0; K < G.pathlenght; K++) {
            currentPosition[K] = ' ';
        }

        // Second Line
        printf("  ");
        for (K = 0; K < G.pathlenght; K++) {
            printf("%c", positionItem[K]);
        }
        printf("\n");

        // Third Line
        printf("  ");
        for (I = 1; I <= G.pathlenght; I++) {
            if (I % 10 == 0) {
                printf("%d", (int)I / 10);
            }
            else {
                printf("|");
            }
        }
        printf("\n");

        // Fourth Line
        printf("  ");
        for (I = 0; I < G.pathlenght; I += 10) {
            printf("1234567890");
        }
        printf("\n");

        // Displaying Player Statistics
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", livesRemaining, P.Count, movesRemaining);
        printf("+---------------------------------------------------+\n");

        // Quit loop if the remaining lives are zero!!
        if (livesRemaining == 0) {
            break;
        }

        // Quit loop if the remaining moves are zero
        if (movesRemaining == 0) {
            break;
        }

        // Determining the next move
        do {
            printf("Next Move [1-%d]: ", G.pathlenght);
            scanf("%d", &movePosition);

            if (movePosition < 1 || movePosition > G.pathlenght) {
                printf("  Out of Range!!!\n");
            }

        } while (movePosition < 1 || movePosition > G.pathlenght);
        printf("\n");

        if (P.History[movePosition - 1] == 1) {
            printf("===============> Dope! You've been here before!\n\n");
            currentPosition[movePosition - 1] = 'V';
            movesRemaining++; // so that the time when it decrements, there is no effect
        }
        else if (G.BOMBPlacement[movePosition - 1] == 1 && G.TREASUREPlacement[movePosition - 1] == 1) {
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
            positionItem[movePosition - 1] = '&';
            currentPosition[movePosition - 1] = 'V';
            livesRemaining--;
            P.Count++;
        }
        else if (G.BOMBPlacement[movePosition - 1] == 1) {
            printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
            positionItem[movePosition - 1] = '!';
            currentPosition[movePosition - 1] = 'V';
            livesRemaining--;
        }
        else if (G.TREASUREPlacement[movePosition - 1] == 1) {
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
            positionItem[movePosition - 1] = '$';
            currentPosition[movePosition - 1] = 'V';
            P.Count++;
        }
        else {
            printf("===============> [.] ...Nothing found here... [.]\n\n");
            positionItem[movePosition - 1] = '.';
            currentPosition[movePosition - 1] = 'V';
        }

        // Store the position in history array
        P.History[movePosition - 1] = 1;

        // Decremenotion the number of moves left
        movesRemaining--;

        if (livesRemaining == 0) {
            printf("No more LIVES remaining!\n\n");
        }
        if (movesRemaining == 0) {
            printf("No more MOVES remaining!\n\n");
        }

    } while (movesRemaining >= 0 && livesRemaining >= 0);

    // Printing the final table

    printf("\n");

    // Ending Lines
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\n");

    printf("You should play again and try to beat your score!\n");
    printf("\n");

    return 0;
}




