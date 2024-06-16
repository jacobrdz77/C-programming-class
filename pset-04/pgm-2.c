#include <stdio.h>

double calculateHousingCosts(double initialCost, double annualFuelCost, float taxRate)
{
    taxRate *= 0.01;
    // Add (initial + fuel cost) * 5 (years)
    double amountAfterFiveyears = (initialCost) + (annualFuelCost * 5);

    // Calculate Tax amount for 5 years
    double taxAmount = (initialCost * taxRate) * 5;

    // Add Tax to amountWFuelForFiveYears
    return amountAfterFiveyears + taxAmount;
}

int main()
{
    double initialCost, annualFuelCost;
    float taxRate;

    while (1)
    {

        printf("Enter home cost (USD):");
        scanf("%lf", &initialCost);
        printf("Enter the tax rate(%%):");
        scanf(" %f", &taxRate);
        printf("Enter annual fuel cost (USD):");
        scanf(" %lf", &annualFuelCost);
        printf("=======================\n");

        double result = calculateHousingCosts(initialCost, annualFuelCost, taxRate);
        printf("Your initial cost of ownership is $%.2lf\n\n", result);
    }

    return 0;
}