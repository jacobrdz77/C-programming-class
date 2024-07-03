#include <stdio.h>
#include <stdbool.h>

bool calculateChange(
    const float paid,
    const float cost,
    unsigned int *const dollars,
    unsigned short *const quarters,
    unsigned short *const dimes,
    unsigned short *const nickels,
    unsigned short *const pennies)
{
    if (cost > paid || cost < 0 || paid < 0)
    {
        printf("Invalid cost or amount paid\n");
        *dollars = 0;
        *quarters = 0;
        *dimes = 0;
        *nickels = 0;
        *pennies = 0;
        return false;
    }
    else if (cost == paid)
    {
        printf("No changeCentsreturned\n");
        *dollars = 0;
        *quarters = 0;
        *dimes = 0;
        *nickels = 0;
        *pennies = 0;
        return false;
    }
    int changeCents = (int)(paid * 100) - (int)(cost * 100);

    *dollars = (int)changeCents / 100;
    changeCents %= 100;

    *quarters = (int)(changeCents / 25);
    changeCents %= 25;

    *dimes = (int)((changeCents) / 10);
    changeCents %= 10;

    *nickels = (int)((changeCents) / 5);
    changeCents %= 5;

    *pennies = (int)((changeCents) / 1);
}

int main()
{
    float cost, paid;
    unsigned int dollars;
    unsigned short quarters, dimes, nickels, pennies;

    printf("Enter the cost (USD): ");
    scanf("%f", &cost);

    printf("Enter amount paid (USD): ");
    scanf("%f", &paid);

    if (calculateChange(paid, cost, &dollars, &quarters, &dimes, &nickels, &pennies))
    {
        printf("Change is :\n");
        printf("\t  %u dollars\n", dollars);
        printf("\t  %u quarters\n", quarters);
        printf("\t  %u dimes\n", dimes);
        printf("\t  %u nickels\n", nickels);
        printf("\t  %u pennies\n", pennies);
    }

    return 0;
}
