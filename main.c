#include <stdio.h>
#include <stdlib.h>

int main()
{
  float x;
  float y;
  printf("Enter a number: ");
  scanf("%f", &x); // Note change of %d to %f8// Complete the y = line below
  y =   x*x+(2*x);
  printf("y: %f\n", y);
  return 0;
}
