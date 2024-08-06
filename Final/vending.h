#ifndef VENDING_H
#define VENDING_H

#include <stdbool.h>
#include <stdio.h>

typedef struct item_s {
  char code[3];
  char name[51];
  float cost;
  unsigned short count;
  unsigned short sold;
} VendingItem;

typedef struct change_s {
  unsigned char quarters;
  unsigned char dimes;
  unsigned char nickels;
  unsigned char pennies;
} Change;

typedef struct vending_s {
  unsigned short itemCount;
  VendingItem *items;
  unsigned short quarters;
  unsigned short dimes;
  unsigned short nickels;
  unsigned short pennies;
  unsigned short attemptedPurchases;
  unsigned short purchaseCount;
  float totalSales;
} VendingMachine;

typedef enum {
  PS_SUCCESS = 0,
  PS_INSUFFICIENT_FUNDS,
  PS_INSUFFICIENT_SUPPLY,
  PS_INVALID_CODE,
  PS_OVERPAYMENT,
  PS_NO_CHANGE,
  PS_COUNT
} PurchaseStatus;

typedef struct purchase_s {
  char code[3];
  float payment;
  PurchaseStatus status;
  Change change;
} Purchase;

void LogVending(FILE *const destinaton,
                const VendingMachine *const vendingMachine);

void LogPurchaseHistogram(FILE *const destination,
                          const VendingMachine *const vendingMachine);

bool ReadPurchase(FILE *const source, Purchase *const purchase);

bool ConfigureVendingMachine(FILE *const source,
                             VendingMachine *const vendingMachine);

bool AttemptPurchase(FILE *const logfile, VendingMachine *const vendingMachine,
                     Purchase *const purchase);
/*
      - logs to vending-out.txt
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

// Calculate Change
// Takes in Paid amount and Price, returns Change struct

Change calculateChange(const float paid, const float cost);

#endif