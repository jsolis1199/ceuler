#!/usr/bin/tcc -run

#include <stdio.h>
#include <math.h>

#include "../src/num.h"
// needed to prevent overflow upon squaring 
unsigned long long modular_mult(unsigned long long n1, unsigned long long n2, unsigned long long m) {
  unsigned long long root = ceil(sqrt(m));
  unsigned long long q1 = n1 / root, q2 = n2 / root;
  unsigned long long r1 = n1 % root, r2 = n2 % root;
  return (((q1 * q2 * ((root * root) % m)) % m) + ((q1 * r2 * root) % m)+ ((q2 * r1 * root) % m) + r1 * r2) % m;
}

unsigned long long modular_pow(unsigned long long n, unsigned long long e, unsigned long long m) {
  unsigned long long r = n % m;
  if (e == 0) {return 1 % m;}
  else if (e == 1) {return r;}
  else if ((e % 2) == 0) {return modular_pow(modular_mult(r, r, m), e / 2, m);}
  else if (e % 2 == 1) {return modular_mult(r, modular_pow(modular_mult(r, r, m), (e - 1) / 2, m), m);}
}

int main(void) {
  unsigned long long n = 1000;
  unsigned long long sum = 0, m = 10000000000;
  for (unsigned long long i = 1; i <= n; i++) {
    sum = (sum + modular_pow(i, i, m)) % m;
  }
  printf("%llu\n", sum);
  return 0;
}
