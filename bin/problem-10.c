#!/usr/bin/tcc -run

#include <stdio.h>

#include "../src/arr.h"

#define LEN 2 * llpowll(10, 6) + 1

int main(void) {
  char sieve[LEN];
  sieve_of_eratosthenes(sieve, LEN);
  unsigned long long sum = 0;
  for (unsigned long i = 0; i < LEN; i++) {if (sieve[i]) sum += i;}
  printf("%llu\n", sum);
  return 0;
}
