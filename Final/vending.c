#include "vending.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRICE 5.00

// Loads config file to VendingMachine
bool ConfigureVendingMachine(FILE *const source,
                             VendingMachine *const vendingMachine) {
  // printf("Configuring Vending Machine\n");
  if (source == NULL) {
    return false;
  }

  fscanf(source, "%d %d %d %d", &vendingMachine->quarters,
         &vendingMachine->dimes, &vendingMachine->nickels,
         &vendingMachine->pennies);
  fscanf(source, "%d", &vendingMachine->itemCount);

  vendingMachine->items =
      (VendingItem *)calloc(vendingMachine->itemCount, sizeof(VendingItem));

  for (int i = 0; i < vendingMachine->itemCount; i++) {
    fscanf(source, "%s %s %f %d", &vendingMachine->items[i].code,
           &vendingMachine->items[i].name, &vendingMachine->items[i].cost,
           &vendingMachine->items[i].count);
  }

  return true;
}

// Prints to destination
void LogVending(FILE *const destinaton,
                const VendingMachine *const vendingMachine) {
  // printf("Logging Vending Machine\n");
  if (destinaton == NULL) {
    perror("Couldn't access destination file.");
    return;
  }
  // printf("Logging Vending Machine\n");

  float percentage = 0;

  if (vendingMachine->attemptedPurchases != 0) {
    percentage = ((float)vendingMachine->purchaseCount /
                  vendingMachine->attemptedPurchases) *
                 100;
  }

  fprintf(destinaton, "Vending Machine:\n\t\t");
  fprintf(destinaton,
          "Total sales:$%4.2f Vending Attempts:  %d Successful:  %d ["
          "%3.2f%%]\n\t\t",
          vendingMachine->totalSales, vendingMachine->attemptedPurchases,
          vendingMachine->purchaseCount, percentage);
  fprintf(destinaton, "Coins: Q:%hu; D:%hu; N:%hu; P:%hu\n\t\t",
          vendingMachine->quarters, vendingMachine->dimes,
          vendingMachine->nickels, vendingMachine->pennies);
  fprintf(destinaton, "Items (%hu):\n\t\t", vendingMachine->itemCount);

  for (int i = 0; i < vendingMachine->itemCount; i++) {
    if (i == vendingMachine->itemCount - 1) {
      // Removes the \t\t at the end of output
      fprintf(destinaton,
              "code:%2s name:%15s cost:%5.2f count:%3hu sold:%3hu\n",
              vendingMachine->items[i].code, vendingMachine->items[i].name,
              vendingMachine->items[i].cost, vendingMachine->items[i].count,
              vendingMachine->items[i].sold);

    } else {
      fprintf(destinaton,
              "code:%2s name:%15s cost:%5.2f count:%3hu sold:%3hu\n\t\t",
              vendingMachine->items[i].code, vendingMachine->items[i].name,
              vendingMachine->items[i].cost, vendingMachine->items[i].count,
              vendingMachine->items[i].sold);
    }
  }
}

void LogPurchaseHistogram(FILE *const destination,
                          const VendingMachine *const vendingMachine) {
  if (destination == NULL) {
    perror("Couldn't access destination file.");
    return;
  }
  fprintf(destination, "Purchase Histogram:\n\t\t");
  fprintf(destination, "items sold: %d\n\t\t", vendingMachine->purchaseCount);

  for (int i = 0; i < vendingMachine->itemCount; i++) {
    float percentage =
        ((float)vendingMachine->items[i].sold / vendingMachine->purchaseCount) *
        100;
    fprintf(destination,
            "code:%s sold:%4hu [%3.2f%%] : ", vendingMachine->items[i].code,
            vendingMachine->items[i].name, vendingMachine->items[i].sold,
            percentage);
    for (int j = 0; j < (int)percentage; j++) {
      fprintf(destination, "*");
    }

    if (i == vendingMachine->itemCount - 1) {
      fprintf(destination, "\n");
    } else {
      fprintf(destination, "\n\t\t");
    }
  }
}

bool ReadPurchase(FILE *const source, Purchase *const purchase) {
  if (source == NULL) {
    return false;
  }

  fscanf(source, "%s %f", &purchase->code, &purchase->payment);

  return true;
}

/*
      - logs to logfile
      - Increment VendingMachine's attemptedPurchases
        - False Cases (handle errors outside of function)
            - if amount is less than price, isSuccessful = false
   (PS_INSUFFICIENT_FUNDS)
            - if the quantity of the item (using the code of Purchase) is 0,
   isSuccessful = false (PS_INSUFFICIENT_SUPPLY)
            - if the code of Purchase is not VALID, isSuccessful = false
   (PS_INVALID_CODE)
            - if amount is greater than limit, isSuccessful = false
   (PS_OVERPAYMENT)
            - if there is no change, isSuccessful = false (PS_NO_CHANGE)

        - True Cases
            - if item is found in vendingMachine->items[]
                - quantity is decremented by 1
                - VendingMachine's purchaseCount is incremented by 1
                - log the purchase info to a file ("purchase_history.txt", mode
                - if amount is greater than price, change = amount - price
                  - decrease VendingMachine's Change
                - if amount is equal to price, change = 0
 */
bool AttemptPurchase(FILE *const logfile, VendingMachine *const vendingMachine,
                     Purchase *const purchase) {
  if (logfile == NULL) {
    return false;
  }
  vendingMachine->attemptedPurchases++;
  printf("Purchase ID: %s\n", purchase->code);
  printf("Payment: %3.2f\n", purchase->payment);

  for (int i = 0; i < vendingMachine->itemCount; i++) {
    purchase->code[0] = toupper(purchase->code[0]);
    printf("Item Code: %s\n", vendingMachine->items[i].code);
    if (strcmp(purchase->code, vendingMachine->items[i].code) == 0) {
      if (purchase->payment < vendingMachine->items[i].cost) {
        purchase->status = PS_INSUFFICIENT_FUNDS;
        fprintf(logfile, "[%04d]: %s - %15s cost:%3.2f paid:%3.2f status:%s\n",
                vendingMachine->attemptedPurchases,
                vendingMachine->items[i].code, vendingMachine->items[i].name,
                vendingMachine->items[i].cost, purchase->payment,
                purchase->status);
        return false;
      } else if (vendingMachine->items[i].count == 0) {
        purchase->status = PS_INSUFFICIENT_SUPPLY;
        fprintf(logfile, "[%04d]: %s - %15s cost:%3.2f paid:%3.2f status:%s\n",
                vendingMachine->attemptedPurchases,
                vendingMachine->items[i].code, vendingMachine->items[i].name,
                vendingMachine->items[i].cost, purchase->payment,
                purchase->status);
        return false;
      } else if (purchase->payment > MAX_PRICE) {
        purchase->status = PS_OVERPAYMENT;
        fprintf(logfile, "[%04d]: %s - %15s cost:%3.2f paid:%3.2f status:%s\n",
                vendingMachine->attemptedPurchases,
                vendingMachine->items[i].code, vendingMachine->items[i].name,
                vendingMachine->items[i].cost, purchase->payment,
                purchase->status);
        return false;
      } else if (purchase->payment > vendingMachine->items[i].cost) {
        purchase->status = PS_SUCCESS;
        vendingMachine->items[i].count--;
        vendingMachine->items[i].sold++;
        vendingMachine->purchaseCount++;
        purchase->change =
            calculateChange(purchase->payment, vendingMachine->items[i].cost);
        vendingMachine->totalSales += vendingMachine->items[i].cost;

        fprintf(logfile,
                "[%04d]: %s - %15s cost:%3.2f paid:%3.2f status:%s             "
                " q:%hu d:%hu "
                "n:%hu p:%hu\n",
                vendingMachine->attemptedPurchases,
                vendingMachine->items[i].code, vendingMachine->items[i].name,
                vendingMachine->items[i].cost, purchase->payment,
                purchase->status, purchase->change.quarters,
                purchase->change.dimes, purchase->change.nickels,
                purchase->change.pennies);
        return true;
      } else {
        purchase->status = PS_NO_CHANGE;
        fprintf(logfile, "[%04d]: %s - %15s cost:%3.2f paid:%3.2f status:%s\n",
                vendingMachine->attemptedPurchases,
                vendingMachine->items[i].code, vendingMachine->items[i].name,
                vendingMachine->items[i].cost, purchase->payment,
                purchase->status);
        return false;
      }
    }
  }
}

Change calculateChange(const float paid, const float cost) {
  Change c;
  if (cost > paid || cost < 0 || paid < 0) {
    printf("Invalid cost or amount paid\n");
    return c;
  } else if (cost == paid) {
    printf("Change: $0.00\n");
    return c;
  }

  int changeCents = (int)(paid * 100) - (int)(cost * 100);

  c.quarters = (int)(changeCents / 25);
  changeCents %= 25;

  c.dimes = (int)((changeCents) / 10);
  changeCents %= 10;

  c.nickels = (int)((changeCents) / 5);
  changeCents %= 5;

  c.pennies = (int)((changeCents) / 1);
  // double change = (c.quarters * 0.25) + (c.dimes * 0.10) + (c.nickels * 0.05)
  // +
  //                 (c.pennies * 0.01);
  // printf("q:%hu d:%hu n:%hu p:%hu\n", c.quarters, c.dimes, c.nickels,
  //        c.pennies);
  return c;
}
