#include <stdio.h>
#include <math.h>

double calculateMonthlyPayment(double principle, double annualInterestRate, int numberOfPayments) {
  double monthlyRate = annualInterestRate / 12;

  return (monthlyRate * principle) / (1 - pow(1 + monthlyRate, (-1) * numberOfPayments));
}

int main() {
  double principle;
  double annualInterestRate;
  int numberOfPayments;

  while (1) {
  printf("Enter the principle (USD):");
  scanf("%lf", &principle);
  printf("Enter the # of monthy payments:");
  scanf(" %d", &numberOfPayments);
  printf("Enter the APR (%%):");
  scanf(" %lf%%", &annualInterestRate);
  annualInterestRate *= 0.01;
  printf("\n\n");

  double monthlyPayment = calculateMonthlyPayment(principle, annualInterestRate, numberOfPayments);
  double totalAmountOwed = monthlyPayment * numberOfPayments;
  double interestPaid = totalAmountOwed - principle;

  printf("Loan Amount:          $%10.2lf\n", principle);
  printf("Annual Interest Rate: $%10.2lf%%\n", annualInterestRate * 100);
  printf("Number of Payments:    %10d\n", numberOfPayments);
  printf("Monthly Payment:      $%10.2lf\n", monthlyPayment);
  printf("Amount Paid Back:     $%10.2lf\n", totalAmountOwed);
  printf("Interest Paid:        $%10.2lf\n", interestPaid);
  printf("\n\n\n");
  }
}
