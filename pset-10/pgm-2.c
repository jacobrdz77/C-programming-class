#include <stdio.h>
#include <math.h>

int gcd(const int p, const int q);

int main()
{
    int p;
    int q;
    printf("Enter two numbers: ");
    scanf("%d %d", &p, &q);
    int userGdc = gcd(p, q);

    printf("GDC: %d", userGdc);
    return 0;
}

int gcd(const int p, const int q)
{
    if (p == 0 || q == 0)
    {
        return 0;
    }

    int absolute_p = abs(p);
    int absolute_q = abs(q);

    int remainder;

    return absolute_p % absolute_q == 0 ? q : gcd(absolute_q, absolute_p % absolute_q);
}