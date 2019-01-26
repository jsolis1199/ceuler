#!/usr/bin/tcc -run

#include <stdio.h>
#include <stdlib.h>

#include "../src/str.h"

int is_not_palindrome(char str[]) {
  int len = strlen(str);
  char cpy[len]; /* + 1]; ? ? ? */
  strcpy(cpy, str);
  strrev(cpy);
  return strcmp(str, cpy);
}

int main(void) {
  long max = 0; 
  char str[7];
  for (int i = 999; i > 99; i--) {
    for (int j = i; j > 99; j--) {
      sprintf(str, "%d", i * j);
      if (!is_not_palindrome(str)) {
        long tmp = strtol(str, NULL, 10);
        if (tmp > max) {
          max = tmp;
        }
      }
    }
  }
  printf("%ld\n", max);
  return 0;
}
