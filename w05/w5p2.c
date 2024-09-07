/*
*****************************************************************************
                          Workshop - #5 (P2)

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define LOG_DAYS 3
#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void) {
    const int JAN = 1;
    const int DEC = 12;
    int continue_loop = 1;
    int Year, Month, i;



    double MOR_RATE, EVE_RATE, MOR_RATE_sum = 0, EVE_RATE_sum = 0;


    printf("General Well-being Log\n");
    printf("======================\n");

    do {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &Year, &Month);
        if (Year < MIN_YEAR || Year > MAX_YEAR) {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        if (Month < JAN || Month > DEC) {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        if (Year >= MIN_YEAR && Year <= MAX_YEAR && Month >= JAN && Month <= DEC) {
            printf("\n");
            printf("*** Log date set! ***\n");
            printf("\n");
        }
    } while (((Year < MIN_YEAR) || (Year > MAX_YEAR)) || ((Month < JAN) || (Month > DEC)));

    do {
        {
            for (i = 1; i < LOG_DAYS + 1; i++) {

                switch (Month) {
                case 1:
                    printf("%d-JAN-0%d\n", Year, i);
                    break;
                case 2:
                    printf("%d-FEB-0%d\n", Year, i);
                    break;
                case 3:
                    printf("%d-MAR-0%d\n", Year, i);
                    break;
                case 4:
                    printf("%d-APR-0%d\n", Year, i);
                    break;
                case 5:
                    printf("%d-MAY-0%d\n", Year, i);
                    break;
                case 6:
                    printf("%d-JUN-0%d\n", Year, i);
                    break;
                case 7:
                    printf("%d-JUL-0%d\n", Year, i);
                    break;
                case 8:
                    printf("%d-AUG-0%d\n", Year, i);
                    break;
                case 9:
                    printf("%d-SEP-0%d\n", Year, i);
                    break;
                case 10:
                    printf("%d-OCT-0%d\n", Year, i);
                    break;
                case 11:
                    printf("%d-NOV-0%d\n", Year, i);
                    break;
                case 12:
                    printf("%d-DEC-0%d\n", Year, i);
                    break;
                }

                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &MOR_RATE);

                while (!(MOR_RATE >= 0.0 && MOR_RATE <= 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%lf", &MOR_RATE);
                }
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &EVE_RATE);

                while (!(EVE_RATE >= 0.0 && EVE_RATE <= 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf", &EVE_RATE);
                }

                // Calculating  morning and evening
                MOR_RATE_sum += MOR_RATE;
                EVE_RATE_sum += EVE_RATE;
                printf("\n");
            }
        }
        continue_loop = 0;

        // Displaying the summary
        printf("Summary\n");
        printf("=======\n");

        // Total FOR ratings
        printf("Morning total rating: %.3lf\n", MOR_RATE_sum);
        printf("Evening total rating:  %.3lf\n", EVE_RATE_sum);
        printf("----------------------------\n");
        printf("Overall total rating: %.3lf\n", MOR_RATE_sum + EVE_RATE_sum);
        printf("\n");

        // Average FOR  ratings
        printf("Average morning rating:  %.1lf\n", MOR_RATE_sum / LOG_DAYS);
        printf("Average evening rating:  %.1lf\n", EVE_RATE_sum / LOG_DAYS);
        printf("----------------------------\n");
        printf("Average overall rating:  %.1lf\n", ((MOR_RATE_sum / LOG_DAYS) + (EVE_RATE_sum / LOG_DAYS)) / 2);
        printf("\n");
    } while (continue_loop == 1);
    return 0;
}
