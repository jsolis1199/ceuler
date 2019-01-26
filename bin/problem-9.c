#!/usr/bin/tcc -run

#include <stdio.h>

long p = 1000;

int main(void) {
  for (long a = 1; a < p; a++) { 
    for (long b = a + 1; b < p - a; b++) {
      if ((p * p + 2 * a * b) == 2 * p * (a + b)) {
        printf("%li\n", a * b * (p - a - b));
      }
    }
  }
  return 0;
}
