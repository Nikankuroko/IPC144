/*
*****************************************************************************
                          Workshop - #6 (P1)

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_ITEMS 10

double mNI;    //monthly NET income
int wLI;       //wishListItems
const double mincost = 100.00; //minimum cost



int main()
{
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    printf("\n");

do{
    printf("Enter your monthly NET income: $");
    scanf("%lf" , &mNI);

    if (mNI < 500.00)
    {
        printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
    }

    if (mNI > 400000.00)
    {
        printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
    }

    printf("\n");
}
while(!(mNI >= 500.00 && mNI <= 400000.00));

    do {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &wLI);

        if (!(wLI > 0 && wLI <= MAX_ITEMS))
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }

        printf("\n");
    }
    while(!(wLI > 0 && wLI <= MAX_ITEMS));


// identify arrays
    double cost[wLI];
    int priority[wLI];
    char finance_options[wLI];

    int i;
    for (i = 1; i <= wLI; i++)
    {
        printf("Item-%d Details:\n", i);


        //value
        do {
            printf("   Item cost: $");
            scanf("%lf", &cost[i - 1]);

            if (cost[i - 1] < mNI)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        }
        while (cost[i - 1] < mNI);

        // Priority
        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i - 1]);

            if ((priority[i - 1] < 1) || (priority[i - 1] > 3))
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        }
        while ((priority[i - 1] < 1) || (priority[i - 1] > 3));


        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance_options[i - 1]);

            if (!(finance_options[i - 1] == 'n' || finance_options[i - 1] == 'y'))
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        }
        while (!(finance_options[i - 1] == 'n' || finance_options[i - 1] == 'y'));

        printf("\n");
    }

    //table
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");



    int K;
    double total_cost = 0;
    for(K = 1; K <= wLI; K++)
    {
        printf("  %d      %d        %c     %10.2lf\n", K, priority[K- 1], finance_options[K - 1], cost[K - 1]);
        total_cost += cost[K - 1];
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $ %.2lf\n", total_cost);
    printf("\n");


    printf("Best of luck in all your future endeavours!\n");

    return 0;
}
