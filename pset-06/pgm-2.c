#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y)
{
  if (x == 0 || y == 0)
  {
    return 0;
  }

  int absolute_x = abs(x);
  int absolute_y = abs(y);

  int remainder;

  do
  {
    remainder = absolute_x % absolute_y;
    // absolute_x will contain the GCD value
    absolute_x = absolute_y;
    absolute_y = remainder;

  } while (absolute_y != 0);

  return absolute_x;
}

int main()
{

  int x;
  int y;
  printf("Enter two numbers(x and y): ");
  scanf("%d %d", &x, &y);
  int userGdc = gcd(x, y);

  printf("GDC: %d", userGdc);

  return 0;
}
