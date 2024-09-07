/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p2.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intPtr) {
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

    if (intPtr != NULL) {
        *intPtr = input;
    }
    return input;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doublePtr) {
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

    if (doublePtr != NULL) {
        *doublePtr = input;
    }
    return input;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int seqNumber) {
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRODUCTS);
    printf("NOTE: A 'serving' is %dg\n\n", GramsPerServing);
}

// 4. Get user input for the details of cat food product
struct catFoodInfo getCatFoodInfo(const int seqNumber) {
    struct catFoodInfo cfi;
    int flag;
    printf("Cat Food Product #%d\n", seqNumber + 1);
    printf("--------------------\n");
    flag = 1;

    // SKU
    printf("SKU           : ");
    flag = 1;
    do {
        scanf("%d", &cfi.sku_number);
        if (cfi.sku_number <= 0) {
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
        scanf("%lf", &cfi.price);
        if (cfi.price <= 0) {
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
        scanf("%lf", &cfi.wl);
        if (cfi.wl <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
        else {
            flag = 0;
        }
    } while (flag);

    // Calories
    printf("CALORIES/SERV.: ");
    flag = 1;
    do {
        scanf("%d", &cfi.cpr);
        if (cfi.cpr <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
        else {
            flag = 0;
        }
    } while (flag);

    printf("\n");

    // Returning the struct
    return cfi;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void) {
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int skuNumber, double* productPrice, int caloriePerServing, double* productWeightLbs) {
    printf("%07d %10.2lf %10.1lf %8d\n", skuNumber, *productPrice, *productWeightLbs, caloriePerServing);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* pounds, double* conversionResultToKg) {
    double poundsToKg = (*pounds) / POUNDSTOKG;

    if (conversionResultToKg != NULL) {
        *conversionResultToKg = poundsToKg;
    }

    return poundsToKg;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* pounds, int* conversionResultToG) {
    int poundsToG = ((*pounds) / POUNDSTOKG) * 1000;

    if (conversionResultToG != NULL) {
        *conversionResultToG = poundsToG;
    }

    return poundsToG;
}

// 10. convert lbs: kg and g
void convertLbs(const double* pounds, double* conversionResultToKg, int* conversionResultToG) {
    double poundsToKg = (*pounds) / POUNDSTOKG;
    int poundsToG = ((*pounds) / POUNDSTOKG) * 1000;

    if (conversionResultToG != NULL && conversionResultToKg != NULL) {
        *conversionResultToG = poundsToG;
        *conversionResultToKg = poundsToKg;
    }
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeGrams, const int totalGrams, double* numberOfServings) {
    double servings = ((double)totalGrams) / servingSizeGrams;

    if (numberOfServings != NULL) {
        *numberOfServings = servings;
    }

    return servings;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* numberOfServings, double* result) {
    double costPerServing = (*price) / (*numberOfServings);

    if (result != NULL) {
        *result = costPerServing;
    }

    return costPerServing;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* totalCalories, double* result) {
    double costPerCal = (*price) / (*totalCalories);

    if (result != NULL) {
        *result = costPerCal;
    }

    return costPerCal;
}

// 14. Derive a reporting detail record based on the cat food product data
struct reportData calculateReportData(const struct catFoodInfo cfi) {
    struct reportData rd;

    // Assigning values from CatFoodInfo
    rd.sku_number = cfi.sku_number;
    rd.price = cfi.price;
    rd.wl = cfi.wl;
    rd.cpr = cfi.cpr;

    // Assigning calculated values
    rd.pwk = convertLbsKg(&rd.wl, &rd.pwk);
    rd.pwg = convertLbsG(&rd.wl, &rd.pwg);
    rd.servings = calculateServings(GramsPerServing, rd.pwg, &rd.servings);

    // Total calories
    double totalCalories = rd.cpr * rd.servings;

    rd.cps = calculateCostPerServing(&rd.price, &rd.servings, &rd.cps);
    rd.ccp = calculateCostPerCal(&rd.price, &totalCalories, &rd.ccp);

    return rd;
}
// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
    printf("Analysis Report (Note: Serving = %dg)\n", GramsPerServing);
    printf("---------------\n");
    printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct reportData rd, const int cheapestProductCheck) {

    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", rd.sku_number, rd.price, rd.wl, rd.pwk, rd.pwg, rd.cpr, rd.servings, rd.cps, rd.ccp);
  
    if (cheapestProductCheck)
    {
        printf(" ***\n");
    }
    else
    {
        printf("\n");
    }
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct catFoodInfo cfi) {
    printf("Final Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%5.2lf\n", cfi.sku_number, cfi.price);
    printf("\n");

    // Ending line
    printf("Happy shopping!\n");
    printf("\n");
}
// 7. Logic entry point
void start(void)
{
    // Struct Arrays
    struct reportData rd[MAX_PRODUCTS] = { {0} };
    struct catFoodInfo cfi[MAX_PRODUCTS] = { {0} };

    // Declaring variables
    int i, cheapestIndex = 0;

    // Printing the opening message
    openingMessage(MAX_PRODUCTS);

    // Filling the cfi array
    for (i = 0; i < MAX_PRODUCTS; i++) {
        cfi[i] = getCatFoodInfo(i);
        rd[i] = calculateReportData(cfi[i]);
    }

    // Displaying cat food header
    displayCatFoodHeader();

    // Displaying cat food data
    for (i = 0; i < MAX_PRODUCTS; i++) {
        displayCatFoodData(cfi[i].sku_number, &cfi[i].price, cfi[i].cpr, &cfi[i].wl);
    }

    // Determining the cheapest product's sku and price
    double cheapestProductPrice = rd[0].cps;
    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        if (rd[i].cps <= cheapestProductPrice)
        {
            cheapestProductPrice = rd[i].cps;
            cheapestIndex = i;
        }
    }
    printf("\n");

    // Displaying the report header
    displayReportHeader();

    // Displaying the report data
    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        displayReportData(rd[i], (i == cheapestIndex));
    }
    printf("\n");

    // Displaying final analysis
    displayFinalAnalysis(cfi[cheapestIndex]);
}

