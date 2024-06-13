#include <stdio.h>
#include <math.h>

int main() {
    char month[9];
    char year[4];
    double amountCollected;
    double stateSalesTax;
    double countySalesTax;

    printf("Enter month: ");
    scanf("%s", month);
    printf("Enter year: ");
    scanf(" %s", year);
    printf("Enter amount collected: ");
    scanf(" %lf", &amountCollected);
    printf("County Sales Tax: ");
    scanf(" %lf", &countySalesTax);
    printf("State Sales Tax: ");
    scanf(" %lf", &stateSalesTax);
    printf("\n");

    // To convert % to decimal
    stateSalesTax *= 0.01;
    countySalesTax *= 0.01;

    double stateSalesTaxAmount = amountCollected * stateSalesTax;
    double countySalesTaxAmount = amountCollected * countySalesTax;
    double totalSalesTaxAmount = stateSalesTaxAmount + countySalesTaxAmount;

    double sales = (amountCollected) / (1 + stateSalesTax + countySalesTax);    

    // Month Report
    printf("Month: %s %s\n", month, year);
    printf("-----------------------------\n");
    printf("Total Collected:  $%10.2lf\n", amountCollected);
    printf("Sales:            $%10.2lf\n", sales);
    printf("County Sales Tax: $%10.2lf\n", countySalesTaxAmount);
    printf("State Sales Tax:  $%10.2lf\n", stateSalesTaxAmount);
    printf("Total Sales Tax:  $%10.2lf\n", totalSalesTaxAmount);
    printf("-----------------------------");

    return 0;
}


/*
A retail company must file a monthly sales tax report listing the sales for the month and the amount of sales tax collected.

Write a program that asks for the month, the year, and the total amount collected at the cash register (that is, merchandise sales plus sales tax).

Allow the user to enter the percentage for the state sales tax and county sales tax.

The amount of product sales may be calculated as:

S = T / (1 + state sales tax + county sales tax)

S is the product sales
T is the total income (product sales plus all sales tax).
 

The program should display a report similar to the following, including numeric formatting:

Month: October 2020
-----------------------------
Total Collected:  $ 26572.89
Sales:            $ 25068.76
County Sales Tax: $   501.38
State Sales Tax:  $  1002.75
Total Sales Tax:  $  1504.13
-----------------------------
TEST CASE:
Month: May, 2023
County Sales Tax = 2.5 %
State Sales Tax = 6.0 %
Total Collected for May 2023 = 133,597.48
*/