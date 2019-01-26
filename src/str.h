#include <string.h>

#include "num.h"

void strrev(char * str) {
  if (str) {
    char tmp;
    for (char * end = str + strlen(str) - 1; str < end; str++, end--) {
      tmp = *str;
      *str = *end;
      *end = tmp;
    }
  }
}

char pop(char str[], int i) {
  char ch = str[i];
  for (int j = i; j < strlen(str); j++) {str[j] = str[j + 1];}
  return ch;
}

void permutation(char perm[], char str[], unsigned long i) {
  int len = strlen(str);
  if (len) {
    int q = factorial(len - 1);
    perm[len - 1] = pop(str, i / q);
    permutation(perm, str, i % q);
  }
  else {
    strrev(perm);
  }
}
