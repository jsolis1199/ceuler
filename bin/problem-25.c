#!/usr/bin/tcc -run

#include <stdio.h>
#include <math.h>

long double f(unsigned int n) {
  long double phi = (1 + sqrtl(5))/2;
  return (powl(phi, n) - powl(-1/phi, -n))/(2*phi - 1);
}

int main(void) {
  int n;
  while (ceill(log10l(roundl(f(n)))) < 1000) {n++;}
  printf("%d\n", n);
  return 0;
}
