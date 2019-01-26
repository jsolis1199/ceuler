#!/usr/bin/tcc -run

#include <stdio.h>

#include "../src/arr.h"

int main(void) {
  unsigned long len = 0;
  while (len /(log(len) + 2) < 10000) {len++;}
  len += 2;
  #define LEN len
  char sieve[LEN];
  sieve_of_eratosthenes(sieve, len);
  int sum = 0;
  unsigned long i = 0;
  while (sum <= 10000) {
    i++;
    if (sieve[i]) {sum++;}
  }
  printf("%ld\n", i);
  return 0;
}
