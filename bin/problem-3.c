#!/usr/bin/tcc -run

#include <stdio.h>
#include <math.h>

#include "../src/arr.h"

int main(void) {
  unsigned long long n = 600851475143;
  int len = log(n) / log(2);
  unsigned long long factorization[len]; 
  int i = 0;
  while (n != 1) {
    factorization[i] = factor(n);
    n /= factorization[i];
    i++;
  }
  printf("%llu\n", max(factorization, i));
  return 0;
}
