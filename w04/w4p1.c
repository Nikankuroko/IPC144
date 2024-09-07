/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{       
    // variuble use for user input
    int loopNM = 0, i = 0;
    //  varuble for charector
    char loopTE = 'R';
    
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");

    while(loopTE != 'Q' || loopNM != 0)
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopTE, &loopNM);

        if (loopTE == 'Q' && loopNM != 0)
        {
            printf("ERROR: To quit, the number of iterations should be 0!\n\n");
        }

        else if (loopTE == 'Q' && loopNM == 0)
        {
            printf("\n");
        }

        else if (loopTE != 'D' && loopTE != 'W' && loopTE != 'F' && loopTE != 'Q')
        {
            printf("ERROR: Invalid entered value(s)!\n\n");
        }

        else if (loopNM < 3 || loopNM > 20)
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
        }

        else if (loopTE == 'D')
        {
            printf("DO-WHILE: ");
            do
            {
                i++;

                printf("D");

            } while (i < loopNM);
            printf("\n\n");
            i = 0;
        }

        else if (loopTE == 'W')
        {
            printf("WHILE   : ");
            while (i < loopNM)
            {
                i++;

                printf("W");
            }
            printf("\n\n");
            i = 0;
        }

        else if (loopTE  == 'F')
        {
            printf("FOR     : ");
            for (i = 0; i < loopNM; i++)
            {
                printf("F");
            }
            printf("\n\n");
            i = 0;
        }



    } 

    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;
}
