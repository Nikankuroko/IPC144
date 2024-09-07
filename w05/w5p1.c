#include <stdio.h>
/*
*****************************************************************************
                          Workshop - #5 (P1)

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main()
{
    const int JAN = 1;
    const int DEC = 12;
    int Year, Month;

    printf("General Well-being Log\n");
    printf("======================\n");
    do {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &Year, &Month);
        if (Year < MIN_YEAR || Year > MAX_YEAR)
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");        
}
        if (Month < JAN || Month > DEC) {
             printf("   ERROR: Jan.(1) - Dec.(12)\n");        
}
        if (Year >= MIN_YEAR && Year <= MAX_YEAR && Month >= JAN && Month <= DEC)
        {
            printf("\n");
        }
    }while (!(Year >= MIN_YEAR && Year <= MAX_YEAR && Month >= JAN && Month <= DEC));

    printf("*** Log date set! ***\n");

    if (Month == 1)
    {
        printf("\n");
        printf("Log starting date: %d-", Year);
        printf("JAN-01\n");
    } else if (Month == 2)
    {
        printf("\n");
        printf("Log starting date: %d-", Year);
        printf("FEB-01\n");
    } else if (Month == 3)
    {
        printf("\n");
        printf("Log starting date: %d-", Year);
        printf("MAR-01\n");
    } else if (Month == 4)
    {
        printf("\n");
        printf("Log starting date: %d-", Year);
        printf("APR-01\n");
    } else if (Month == 5)
    {
        printf("\n");
        printf("Log starting date: %d-", Year);
        printf("MAY-01\n");
    } else if (Month == 6)
    {
        printf("\n");
        printf("Log starting date: %d-", Year);
        printf("JUN-01\n");
    } else if (Month == 7)
    {
        printf("\n");
        printf("Log starting date: %d-", Year);
        printf("JUL-01\n");
    } else if (Month == 8)
    {
        printf("\n");
        printf("Log starting date: %d-", Year);
        printf("AUG-01\n");
    } else if (Month == 9)
    {
        printf("\n");
        printf("Log starting date: %d-", Year);
        printf("SEP-01\n");
    } else if (Month == 10)
    {
        printf("\n");
        printf("Log starting date: %d-", Year);
        printf("OCT-01\n");
    } else if (Month == 11)
    {
        printf("\n");
        printf("Log starting date: %d-", Year);
        printf("NOV-01\n");
    } else if (Month == 12)
    {
        printf("\n");
        printf("Log starting date: %d-", Year);
        printf("DEC-01\n");
    }


    return 0;
}
