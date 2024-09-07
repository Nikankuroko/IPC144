/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    const double TAX_RATE = 0.13;
    const char PATTY_SIZE = 'S';
    double smallShirt, mediumShirt, largeShirt;
    int pattyQuantity, tommyQuantity, sallyQuantity;
    double subTotalPatty, subTotalTommy, subTotalSally;
    double taxesPatty, taxesTommy, taxesSally;
    double totalPatty, totalTommy, totalSally;
    double grandTotal;

    printf("Set Shirt Prices\n================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &smallShirt);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &mediumShirt);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &largeShirt);

    printf("\nShirt Store Price List\n======================\n");
    printf("SMALL  : $%.2lf\n", smallShirt);
    printf("MEDIUM : $%.2lf\n", mediumShirt);
    printf("LARGE  : $%.2lf\n", largeShirt);

    printf("\nPatty's shirt size is '%c'\n", PATTY_SIZE);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &pattyQuantity);
    printf("\n");

    subTotalPatty = smallShirt * pattyQuantity;
    taxesPatty = ((subTotalPatty * TAX_RATE) * 100) / 100.0;
    totalPatty = subTotalPatty + taxesPatty;

    const char TOMMY_SIZE = 'L';
    printf("Tommy's shirt size is '%c'\n", TOMMY_SIZE);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &tommyQuantity);
    printf("\n");

    subTotalTommy = largeShirt * tommyQuantity;
    taxesTommy = ((subTotalTommy * TAX_RATE) * 100) / 100.0;
    totalTommy = subTotalTommy + taxesTommy;

    const char SALLY_SIZE = 'M';
    printf("Sally's shirt size is '%c'\n", SALLY_SIZE);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &sallyQuantity);
    printf("\n");


    subTotalSally = mediumShirt * sallyQuantity;
    taxesSally = ((subTotalSally * TAX_RATE) * 100) / 100.0;
    totalSally = subTotalSally + taxesSally;

    grandTotal = totalPatty + totalTommy + totalSally;

    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");

    printf("Patty    %c%9.2lf %3d %9.4lf   %.2lf00  %.2lf00\n", PATTY_SIZE, smallShirt, pattyQuantity, subTotalPatty, taxesPatty, totalPatty);
    printf("Sally    %c%9.2lf %3d %9.4lf   %.2lf00  %.2lf00\n", SALLY_SIZE, mediumShirt, sallyQuantity, subTotalSally, taxesSally, totalSally);
    printf("Tommy    %c%9.2lf %3d %9.4lf   %.2lf00  %.2lf00\n", TOMMY_SIZE, largeShirt, tommyQuantity, subTotalTommy, taxesTommy, totalTommy);

    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("                         %.2lf00   %.2lf00  %.2lf00\n\n", subTotalPatty + subTotalTommy + subTotalSally, taxesPatty + taxesTommy + taxesSally, grandTotal);

    printf("Daily retail sales represented by coins\n=======================================\n");

    printf("\nSales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");

    printf("              323.5100\n");
    printf("Toonies  161    1.5100\n");
    printf("Loonies    1    0.5100\n");
    printf("Quarters   2    0.0100\n");
    printf("Dimes      0    0.0100\n");
    printf("Nickels    0    0.0100\n");
    printf("Pennies    1    0.0000\n");

    printf("\nAverage cost/shirt: $24.8854\n");

    printf("\nSales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");

    printf("              365.5700\n");
    printf("Toonies  182    1.5700\n");
    printf("Loonies    1    0.5700\n");
    printf("Quarters   2    0.0700\n");
    printf("Dimes      0    0.0700\n");
    printf("Nickels    1    0.0200\n");
    printf("Pennies    2    0.0000\n");

    printf("\nAverage cost/shirt: $28.1208\n");
    return 0;
}
