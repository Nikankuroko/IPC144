/*
*****************************************************************************
                          Workshop - #4 (P2)

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    
    int numberOfApples, numberOfOranges, numberOfPears, numberOfTomatoes, numberOfCabbages ;
    int applesPicked = 0, orangesPicked = 0, pearsPicked = 0, tomatoesPicked = 0, cabbagesPicked = 0 ,continueShopping = 1;
    

    while (continueShopping == 1)
    {
      
        printf("Grocery Shopping\n");
        printf("================\n");


        printf("How many APPLES do you need? : ");
        scanf("%d", &numberOfApples);


        while (numberOfApples < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many APPLES do you need? : ");
            scanf("%d", &numberOfApples);
        }
        printf("\n");

        
        printf("How many ORANGES do you need? : ");
        scanf("%d", &numberOfOranges);


        while (numberOfOranges < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many ORANGES do you need? : ");
            scanf("%d", &numberOfOranges);
        }
        printf("\n");

  
        printf("How many PEARS do you need? : ");
        scanf("%d", &numberOfPears);

  
        while (numberOfPears < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many PEARS do you need? : ");
            scanf("%d", &numberOfPears);
        }
        printf("\n");

     
        printf("How many TOMATOES do you need? : ");
        scanf("%d", &numberOfTomatoes);

      
        while (numberOfTomatoes < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &numberOfTomatoes);
        }
        printf("\n");

       
        printf("How many CABBAGES do you need? : ");
        scanf("%d", &numberOfCabbages);

        
        while (numberOfCabbages < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &numberOfCabbages);
        }
        printf("\n");

      
        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");
        printf("\n");


        
        while (numberOfApples > 0)
        {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &applesPicked);

            if (applesPicked > numberOfApples)
            {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", numberOfApples);
            }

            else if (applesPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }

            else if ((applesPicked < numberOfApples) && (applesPicked > 0))
            {
                printf("Looks like we still need some APPLES...\n");
                numberOfApples = numberOfApples - applesPicked;
            }

            else if (applesPicked == numberOfApples)
            {
                printf("Great, that's the apples done!\n\n");
                break;
            }
        }

        
        while (numberOfOranges > 0)
        {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &orangesPicked);

            if (orangesPicked > numberOfOranges)
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", numberOfOranges);
            }

            else if (orangesPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }

            else if ((orangesPicked < numberOfOranges) && (orangesPicked > 0))
            {
                printf("Looks like we still need some ORANGES...\n");
                numberOfOranges = numberOfOranges - orangesPicked;
            }

            else if (orangesPicked == numberOfOranges)
            {
                printf("Great, that's the oranges done!\n\n");
                break;
            }
        }

      
        while (numberOfPears > 0)
        {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &pearsPicked);

            if (pearsPicked > numberOfPears)
            {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", numberOfPears);
            }

            else if (pearsPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }

            else if ((pearsPicked < numberOfPears) && (pearsPicked > 0))
            {
                printf("Looks like we still need some PEARS...\n");
                numberOfPears = numberOfPears - pearsPicked;
            }

            else if (pearsPicked == numberOfPears)
            {
                printf("Great, that's the pears done!\n\n");
                break;
            }
        }

        
        while (numberOfTomatoes > 0)
        {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &tomatoesPicked);

            if (tomatoesPicked > numberOfTomatoes)
            {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", numberOfTomatoes);
            }

            else if (tomatoesPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }

            else if ((tomatoesPicked < numberOfTomatoes) && (tomatoesPicked > 0))
            {
                printf("Looks like we still need some TOMATOES...\n");
                numberOfTomatoes = numberOfTomatoes - tomatoesPicked;
            }

            else if (tomatoesPicked == numberOfTomatoes)
            {
                printf("Great, that's the tomatoes done!\n\n");
                break;
            }
        }

        
        while (numberOfCabbages > 0)
        {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d", &cabbagesPicked);

            if (cabbagesPicked > numberOfCabbages)
            {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", numberOfCabbages);
            }

            else if (cabbagesPicked <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }

            else if ((cabbagesPicked < numberOfCabbages) && (cabbagesPicked > 0))
            {
                printf("Looks like we still need some CABBAGES...\n");
                numberOfCabbages = numberOfCabbages - cabbagesPicked;
            }

            else if (cabbagesPicked == numberOfCabbages)
            {
                printf("Great, that's the cabbages done!\n\n");
                break;
            }
        }

        printf("All the items are picked!\n\n");

        
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &continueShopping);
        printf("\n");

    }

   
    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}
