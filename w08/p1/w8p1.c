/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* pv) {
    int input;
    int flag = 1;

    do {
        scanf("%d", &input);
        if (input <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
        else {
            flag = 0;
        }
    } while (flag);

    if (pv != NULL) {
        *pv = input;
    }
    return input;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doublepv) {
    double input;
    int flag = 1;

    do {
        scanf("%lf", &input);
        if (input <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
        else {
            flag = 0;
        }
    } while (flag);

    if (doublepv != NULL) {
        *doublepv = input;
    }
    return input;
}

// 3. Opening Message (include the number of products that need entering)
void Opening_Message(const int num) {
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", Max_PRODUCTS);
    printf("NOTE: A 'serving' is %dg\n\n", Gramsperserving);
}

// 4. Get user input for the details of cat food product
struct catfoodInfo getcatfoodInfo(const int num) {
    struct catfoodInfo numb;
    int flag;

    printf("Cat Food Product #%d\n", num + 1);
    printf("--------------------\n");

    flag = 1;

    // SKU!
    printf("SKU           : ");
    flag = 1;
    do {
        scanf("%d", &numb.sku_number);

        if (numb.sku_number <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
        else {
            flag = 0;
        }
    } while (flag);

    // Price          
    printf("PRICE         : $");
    flag = 1;
    do {
        scanf("%lf", &numb.price);
        if (numb.price <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
        else {
            flag = 0;
        }
    } while (flag);

    // Weight
    printf("WEIGHT (LBS)  : ");
    flag = 1;
    do {
        scanf("%lf", &numb.wl);
        if (numb.wl <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
        else {
            flag = 0;
        }
    } while (flag);

    // CPR
    printf("CALORIES/SERV.: ");
    flag = 1;
    do {
        scanf("%d", &numb.cpr);
        if (numb.cpr <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
        else {
            flag = 0;
        }
    } while (flag);

    printf("\n");

    // Returning the struct
    return numb;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void) {
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku_number, double* price, int cpr, double* wl) {
    printf("%07d %10.2lf %10.1lf %8d\n", sku_number, *price, *wl, cpr);
}

// 7. Logic entry point
void start(void) {
    int N;
    struct catfoodInfo cfi[Max_PRODUCTS] = { {0} };
    Opening_Message(Max_PRODUCTS);

    for (N = 0; N < Max_PRODUCTS; N++) {
        cfi[N] = getcatfoodInfo(N);
    }

    displayCatFoodHeader();

    for (N = 0; N < Max_PRODUCTS; N++) {
        displayCatFoodData(cfi[N].sku_number, &cfi[N].price, cfi[N].cpr, &cfi[N].wl);
    }
}

