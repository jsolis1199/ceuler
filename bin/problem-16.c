#!/usr/bin/tcc -run

#include <stdio.h>
#include <math.h>

int main(void) {
  char str[400];
  int sum = 0;
  sprintf(str, "%lf", pow(2, 1000));
  for (char * c = &str[0]; *c != '.'; c++) {sum += *c - '0';}
  printf("%d\n", sum);
  return 0;
}
