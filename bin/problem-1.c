#!/usr/bin/tcc -run

#include <stdio.h>

#include "../src/num.h"

int main(void) {
  int a = 3;
  int b = 5;
  int n = 1000 - 1;
  printf("%llu\n", a * sum_of_powers(n / a, 1) + b * sum_of_powers(n / b, 1) - a * b * sum_of_powers(n / (a * b), 1));
  return 0;
}
