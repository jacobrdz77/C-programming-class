#include <stdio.h>

// PGM 1
int salesTax() {
    const double STATE_SALES_TAX = 0.04;
    const double COUNTY_SALES_TAX = 0.02;

    double purchaseAmount;
    printf("Enter purchase amount: ");
    scanf("%lf", &purchaseAmount);   

    double stateTaxAmount = purchaseAmount * STATE_SALES_TAX;
    double countyTaxAmount = purchaseAmount * COUNTY_SALES_TAX;
    double totalAmount = purchaseAmount + stateTaxAmount + countyTaxAmount;

    printf("Purchase amount: $%lf\n", purchaseAmount);
    printf("State sales tax: $%lf\n", stateTaxAmount);
    printf("County sales tax: $%lf\n", countyTaxAmount);
    printf("Total amount: $%lf\n", totalAmount);
    return 0;
}

// PGM 2
int tipTaxTotal() {
    // Ask for user input for the charge of the food
    const double TIP = 0.15;
    const double SALES_TAX = 0.07;

    double purchaseAmount;
    printf("Enter meal purchase amount: ");
    scanf("%lf", &purchaseAmount);   

    double tipAmount = purchaseAmount * TIP;
    double salesTaxAmount = purchaseAmount * SALES_TAX;
    double totalAmount = purchaseAmount + tipAmount + salesTaxAmount;

    printf("Meal purchase amount: $%lf\n", purchaseAmount);
    printf("Tip amount: $%lf\n", tipAmount);
    printf("Sales tax: $%lf\n", salesTaxAmount);
    printf("Total amount: $%lf\n", totalAmount);

    return 0;
}

// PGM 3
int stockTransactionProgram() {
   const int SHARES = 2500;
   const double SHARE_PRICE = 32.87;
   const double COMMISSION_RATE = 0.02;

   double amountPaid = SHARES * SHARE_PRICE;
   double commissionPaidForPurchase = amountPaid * COMMISSION_RATE;

   const int SHARES_SOLD = 1000;
   const double SHARES_SOLD_PRICE = 33.92;
   double amountSold = SHARES_SOLD * SHARES_SOLD_PRICE;
   double commissionPaidForSell = amountSold * COMMISSION_RATE;

   double profit = (amountSold - amountPaid) - (commissionPaidForPurchase + commissionPaidForSell);


    printf("Amount paid for the stocks: $%lf\n", amountPaid);
    printf("Commission paid on the purchase: $%lf\n", commissionPaidForPurchase);
    printf("Amount the stock sold for: $%lf\n", amountSold);
    printf("Commission paid on the sale: $%lf\n", commissionPaidForSell);
    printf("Profit (or loss if negative): $%lf\n", profit);
    return 0;
}


int main() {

    salesTax();
    tipTaxTotal();
    stockTransactionProgram();

    return 0;
}
