#include <math.h>
#include <stdbool.h>
#include <stdio.h>

float calculateBMI(const unsigned short wt_lb, const unsigned short ht_in) {
  return (703 * wt_lb) / pow(ht_in, 2);
}

const char *categorizeWeight(float BMI) {
  if (BMI < 18.5) {
    return "Underweight";
  } else if (BMI >= 18.5 && BMI < 25) {
    return "Normal";
  } else if (BMI >= 25.0 && BMI < 30) {
    return "Overweight";
  } else if (BMI >= 30.0) {
    return "Obese";
  } else {
    return "";
  }
}

int main() {
  unsigned short weigth_lb;
  unsigned short height_in;
  printf("Enter your weight(lbs):");
  scanf("%hu", &weigth_lb);
  printf("Enter your height(inch):");
  scanf(" %hu", &height_in);

  float BMI = calculateBMI(weigth_lb, height_in);
  const char *category = categorizeWeight(BMI);

  printf("BMI: %f\n", BMI);
  printf("Category: %s\n", category);

  return 0;
}
