#!/usr/bin/tcc -run

#include <stdio.h>

int main(void) {
  int sum = 0;
  int first = 1;
  int second = 2;
  int next;
  while (second < 4000000) {
    if ( second % 2 == 0 ) {
      sum += second;
    }
    next = first + second;
    first = second;
    second = next;
  }
  printf("%d\n", sum);
  return 0;
}
