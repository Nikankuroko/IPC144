/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)


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


    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
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
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
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
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

    
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
    printf("\n");


    return 0;
}
