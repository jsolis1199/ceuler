#!/usr/bin/tcc -run

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../src/arr.h"

int main(void) {
  int n = 20;
  unsigned long long arr[n];
  range(arr, 1, n + 1);
  printf("%llu\n", alcm(arr, n));
  return 0;
}
