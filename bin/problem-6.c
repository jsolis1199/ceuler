#!/usr/bin/tcc -run

#include <stdio.h>
#include <math.h>

#include "../src/num.h"

int main(void) {
  unsigned long long n = 100;
  printf("%d\n", (long)(pow(sum_of_powers(n, 1), 2) - sum_of_powers(n, 2)));
  return 0;
}
