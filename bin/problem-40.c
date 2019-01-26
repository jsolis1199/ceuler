#!/usr/bin/tcc -run

#include <stdio.h>

#include "../src/num.h"

unsigned long long get_digit(unsigned long long n, unsigned long long r) {
  char str[10];
  sprintf(str, "%llu", n);
  return str[r] - '0';
}

unsigned long long get_champernowne_digit(unsigned long long n) {
  unsigned long long e = 1, sum = 0;
  while (sum + 9 * e * llpowll(10, e - 1) < n) {
    sum += 9 * e * llpowll(10, e - 1); 
    e++;
  }
  if (e == 1) { return n;}
  else {
    unsigned long long m = n - sum - 1;
    unsigned long long q = m / e, r = m % e;
    return get_digit(llpowll(10, e - 1) + q, r);
  }
}

int main(void) {
  unsigned long long prod = 1;
  for (unsigned long long i = 0; i < 7; i++) {
    prod *= get_champernowne_digit(llpowll(10, i));
  }
  printf("%llu\n", prod);
  return 0;
}
