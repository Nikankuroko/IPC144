/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    // Variable declarations
   const int productId1 = 111, productId2 = 222, productId3 = 111;
   const double productprice1 = 111.49, productprice2 = 222.99, productprice3 = 334.49;
   const char producttaxed1 = 'Y', producttaxed2 = 'N', producttaxed3 = 'N';
   double averageprice;

    averageprice = (productprice1 + productprice2 + productprice3) / 3;
    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n  Taxed: %c\n  Price: $%.4f\n", productId1, producttaxed1, productprice1);
    printf("\n");
    printf("Product-2 (ID:%d)\n  Taxed: %c\n  Price: $%.4f\n", productId2, producttaxed2, productprice2);
    printf("\n");
    printf("Product-3 (ID:%d)\n  Taxed: %c\n  Price: $%.4f\n", productId3, producttaxed3, productprice3);
    printf("\n");
      printf("The average of all prices is: $%.4f\n",averageprice);
      printf("\n");
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n"); 
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n");
    printf("\n");
    //displaying test scenarios
    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", producttaxed1 == 'Y');
printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n",  producttaxed2 == 'N');
printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue,testValue == productprice3);
printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", productprice3 > (productprice1 + productprice2));
printf("5. Is the price of product 1 equal to or more than the price difference");
printf("\n   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n", productprice1 >= (productprice3 - productprice2), productprice3- productprice2);
printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", productprice2 >=  averageprice);
printf("7. Based on product ID, product 1 is unique -> %d\n\n", (productId1 != productId2 && productId1 != productId3));
printf("8. Based on product ID, product 2 is unique -> %d\n\n", (productId2 != productId3 && productId2 != productId1));
printf("9. Based on product ID, product 3 is unique -> %d\n", (productId3 != productId2 && productId3 != productId1));
    return 0;
}
