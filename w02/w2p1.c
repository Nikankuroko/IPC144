/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)


I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';

    printf("Set Shirt Prices\n");
    printf("================\n");

    double Small, Medium, Large;

    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &Small);

    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &Medium);

    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &Large);

    printf("\nShirt Store Price List\n");
    printf("======================\n");

    printf("SMALL  : $%.2lf\n", Small);
    printf("MEDIUM : $%.2lf\n", Medium);
    printf("LARGE  : $%.2lf\n", Large);

    printf("\nPatty's shirt size is '%c'\n", patSize);

    printf("Number of shirts Patty is buying: ");
    int number_shirts;
    scanf("%d", &number_shirts);

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", number_shirts);

    double SubTotal, Taxes, Total;
   
    SubTotal = number_shirts * Small;
    /*TAX = SubTotal * TAX;*/
    Taxes = TAX * SubTotal;
    
    

   long totalCents = (long)(Taxes * 100.0 + 0.5);
   Taxes = totalCents/100.0; 
   Total = SubTotal + Taxes;
    printf("Sub-total: $%.4lf\n", SubTotal);
    printf("Taxes    : $ %.4lf\n", Taxes);
    printf("Total    : $%.4lf\n", Total);

    return 0;
}
