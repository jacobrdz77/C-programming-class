#include <stdio.h>

const float PKG_A_BASE_RATE = 15;
const unsigned short PKG_A_COVERED_HOURS = 50;
const float PKG_A_OVERAGE_RATE = 2.0;
const float PKG_B_BASE_RATE = 20;
const unsigned short PKG_B_COVERED_HOURS = 100;
const float PKG_B_OVERAGE_RATE = 1.5;
const float PKG_C_BASE_RATE = 25;
const unsigned short PKG_C_COVERED_HOURS = 150;
const float PKG_C_OVERAGE_RATE = 1.0;

float calculatePkgA(unsigned short hours)
{
    float total = PKG_A_BASE_RATE;

    if (hours > PKG_A_COVERED_HOURS)
    {
        unsigned short additionalhours = hours - PKG_A_COVERED_HOURS;
        total += additionalhours * PKG_A_OVERAGE_RATE;
    }
    return total;
}
float calculatePkgB(unsigned short hours)
{

    float total = PKG_B_BASE_RATE;

    if (hours > PKG_B_COVERED_HOURS)
    {
        unsigned short additionalhours = hours - PKG_B_COVERED_HOURS;
        total = total + (float)(additionalhours * PKG_B_OVERAGE_RATE);
    }
    return total;
}
float calculatePkgC(short unsigned hours)
{
    float total = PKG_C_BASE_RATE;

    if (hours > PKG_C_COVERED_HOURS)
    {
        unsigned short additionalhours = hours - PKG_C_COVERED_HOURS;
        total += additionalhours * PKG_C_OVERAGE_RATE;
    }
    return total;
}

float calculatePackage(
    float baseRate,
    unsigned short coveredHours,
    float overageRate,
    unsigned short hoursConsumed)
{
    float total = baseRate;

    if (hoursConsumed > coveredHours)
    {
        unsigned short additionalHours = hoursConsumed - coveredHours;
        total += additionalHours * overageRate;
    }

    return total;
}

unsigned short getHours()
{
    unsigned short hours;

    printf("Enter the # of hours of access used: ");
    scanf("%hu", &hours);
    return hours;
}

int main()
{
    unsigned short hours = getHours();

    double planACost = calculatePkgA(hours);
    printf("Under plan A your cost is: $%.2lf\n", planACost);

    double planBCost = calculatePkgB(hours);
    printf("Under plan B your cost is: $%.2lf\n", planBCost);

    double planCCost = calculatePkgC(hours);
    printf("Under plan C your cost is: $%.2lf\n\n", planCCost);

    printf("Bonus:\n");

    double bonusPlanACost = calculatePackage(PKG_A_BASE_RATE, PKG_A_COVERED_HOURS, PKG_A_OVERAGE_RATE, hours);
    printf("Under plan A your cost is: $%.2lf\n", bonusPlanACost);

    double bonusPlanBCost = calculatePackage(PKG_B_BASE_RATE, PKG_B_COVERED_HOURS, PKG_B_OVERAGE_RATE, hours);
    printf("Under plan B your cost is: $%.2lf\n", bonusPlanBCost);

    double bonusPlanCCost = calculatePackage(PKG_C_BASE_RATE, PKG_C_COVERED_HOURS, PKG_C_OVERAGE_RATE, hours);
    printf("Under plan C your cost is: $%.2lf\n", bonusPlanCCost);
    return 0;
}