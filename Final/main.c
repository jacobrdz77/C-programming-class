#include "vending.h"
#include <stdlib.h>

int main() {

  VendingMachine vm = {
      .itemCount = 0,
      .items = NULL,
      .quarters = 0,
      .dimes = 0,
      .nickels = 0,
      .pennies = 0,
      .attemptedPurchases = 0,
      .purchaseCount = 0,
      .totalSales = 0.0,
  };

  // Configure the vending machine
  FILE *config = fopen("config.txt", "r");
  if (!ConfigureVendingMachine(config, &vm)) {
    printf("Error configuring vending machine");
    return 0;
  }
  fclose(config);

  FILE *vendingOutput = fopen("vending-out.txt", "w");
  if (vendingOutput == NULL) {
    printf("Error opening vending output file");
    return 0;
  }
  LogVending(vendingOutput, &vm);
  LogVending(stdout, &vm);

  // Proccess Purchases
  FILE *purchasesFile = fopen("purchases.txt", "r");
  if (purchasesFile == NULL) {
    printf("Error opening purchases file");
    return 0;
  }

  // Read until the end of the file
  while (!feof(purchasesFile)) {
    Purchase purchase;
    if (!ReadPurchase(purchasesFile, &purchase)) {
      printf("Error reading purchase");
      fclose(purchasesFile);
      return 0;
    }

    printf("Processing purchase: %s\n", purchase.code);
    AttemptPurchase(stdout, &vm, &purchase);
    AttemptPurchase(vendingOutput, &vm, &purchase);
    //   printf("Error attempting purchase");
    //   fclose(purchasesFile);
    //   fclose(vendingOutput);
    //   return 0;
  }
  fclose(purchasesFile);

  LogVending(vendingOutput, &vm);
  LogPurchaseHistogram(vendingOutput, &vm);
  fclose(vendingOutput);

  free(vm.items);

  return 1;
}