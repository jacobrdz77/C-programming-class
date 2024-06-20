#include <math.h>
#include <stdbool.h>
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

char getPlan();
bool isPlanValid(const char plan);
bool areHoursValid(const unsigned short hours);
float calculatePkgA(unsigned short hours);
float calculatePkgB(unsigned short hours);
float calculatePkgC(unsigned short hours);
float calculatePackage(float baseRate, unsigned short coveredHours,
                       float overageRate, unsigned short hoursConsumed);
unsigned short getHours();

bool isPlanValid(const char plan)
{
  switch (plan)
  {
  case 'A':
    return 1;
  case 'B':
    return 1;
  case 'C':
    return 1;
  default:
    return 0;
  }
}
bool areHoursValid(const unsigned short hours)
{
  if (hours > 744)
  {
    return false;
  }
  else
  {
    return true;
  }
}
float calculatePkgA(unsigned short hours)
{

  float total = calculatePackage(PKG_A_BASE_RATE, PKG_A_COVERED_HOURS,
                                 PKG_A_OVERAGE_RATE, hours);
  return total;
}
float calculatePkgB(unsigned short hours)
{

  float total = calculatePackage(PKG_B_BASE_RATE, PKG_B_COVERED_HOURS,
                                 PKG_B_OVERAGE_RATE, hours);
  return total;
}
float calculatePkgC(short unsigned hours)
{
  float total = calculatePackage(PKG_C_BASE_RATE, PKG_C_COVERED_HOURS,
                                 PKG_C_OVERAGE_RATE, hours);
  return total;
}

float calculatePackage(float baseRate, unsigned short coveredHours,
                       float overageRate, unsigned short hoursConsumed)
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

char getPlan()
{
  char plan;

  printf("Choose your plan:");
  scanf("%c", &plan);
  return plan;
}

int main()
{
  char chosenPlan = getPlan();
  if (!isPlanValid(chosenPlan))
  {
    printf("Package %c is invalid. Exiting...", chosenPlan);
    return 0;
  }

  unsigned short hours = getHours();
  if (!areHoursValid(hours))
  {
    printf("Hours exceeds limit. Exiting...");
    return 0;
  }
  double planCost;

  switch (chosenPlan)
  {
  case 'A':
     planCost = calculatePkgA(hours);
    break;
  case 'B':
    planCost = calculatePkgB(hours);
    break;
  case 'C':
    planCost = calculatePkgC(hours);
    break;
  default:
    break; 
  }

  printf("Under plan %c your cost is: $%.2lf\n", chosenPlan, planCost);

  return 0;
}
