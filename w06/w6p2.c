/*
*****************************************************************************
                        Workshop - #6 (P2)

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#define MAX_ITEMS 10


double mNI;    //monthly NET income
int wLI;       //wishListItems
const double mincost = 100.00; //minimum cost
int selection;
int item, select = 0;
int pF, n;                        //pf=piority filters and N=first letter of my name(my hand sign for this code)
double cost_of_priority_items = 0;
double years, months, remaining_months; //for calculating years months and remaning months
int continue_loop;


int main()
{
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    printf("\n");

    do {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &mNI);

        if (mNI < 500.00)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }

        if (mNI > 400000.00)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }

        printf("\n");
    } while (!(mNI >= 500.00 && mNI <= 400000.00));

    do {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &wLI);

        if (!(wLI > 0 && wLI <= MAX_ITEMS))
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }

        printf("\n");
    } while (!(wLI > 0 && wLI <= MAX_ITEMS));


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
        } while (cost[i - 1] < mNI);

        // Priority
        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i - 1]);

            if ((priority[i - 1] < 1) || (priority[i - 1] > 3))
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while ((priority[i - 1] < 1) || (priority[i - 1] > 3));


        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance_options[i - 1]);

            if (!(finance_options[i - 1] == 'n' || finance_options[i - 1] == 'y'))
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (!(finance_options[i - 1] == 'n' || finance_options[i - 1] == 'y'));

        printf("\n");
    }

    //table
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");



    int K;
    double total_cost = 0;
    for (K = 1; K <= wLI; K++)
    {
        printf("  %d      %d        %c     %10.2lf\n", K, priority[K - 1], finance_options[K - 1], cost[K - 1]);
        total_cost += cost[K - 1];
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $ %10.2lf\n", total_cost);
    printf("\n");


    do {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");

        printf("Selection: ");
        scanf("%d", &selection);
        printf("\n");

        if (selection == 0) {
            continue_loop = 0;
        }
        else if (selection == 1) {
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", total_cost);

            // Calculating years and months remaning month
            months = (total_cost / mNI) + 0.5;
            years = ((int)months) / 12;
            remaining_months = (months - (years * 12)) + 0.5;
            printf("Forecast: %d years, %d months\n", (int)years, (int)remaining_months);

            // For loop to check whether 'y' exists in finance_options array
            select = 0;
            for (item = 0; item < wLI; item++)
            {
                if (finance_options[item] == 'y') {
                    select += 1;
                }
            }
            if (select != 0)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");

                printf("====================================================\n");
                printf("\n");
            }
        }

        else if (selection == 2) {
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &pF);
            printf("\n");
            cost_of_priority_items = 0;//Reset the variable before calculating the amount for the current priority filter

            printf("====================================================\n");
            printf("Filter:   by priority (%d)\n", pF);
            for (n = 0; n < wLI; n++)
            {
                if (priority[n] == pF) {
                    cost_of_priority_items += cost[n];
                }
            }

            // Calculating years and months
            months = (cost_of_priority_items / mNI) + 0.5;
            years = ((int)months) / 12;
            remaining_months = (months - (years * 12)) + 0.5;

            printf("Amount:   $%.2lf\n", cost_of_priority_items);
            printf("Forecast: %d years, %d months\n", (int)years, (int)remaining_months);

            // For loop to check whether 'y' exists in finance_options array
            select = 0;
            for (item = 0; item < wLI; item++)
            {
                if (finance_options[item] == 'y' && priority[item] == pF) {
                    select += 1;
                }
            }
            if (select != 0)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
                printf("====================================================\n");
                printf("\n");
            
        }

        else if (selection < 0 || selection > 2) {
            printf("ERROR: Invalid menu selection.\n");
            printf("\n");
        }

    } while (selection != 0);


    printf("Best of luck in all your future endeavours!\n");

    return 0;
}
