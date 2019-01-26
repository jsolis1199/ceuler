#!/usr/bin/tcc -run

#include <stdio.h>
#include <string.h>

#include "../src/str.h"

int main(void) {
  char str[] = "0123456789";
  char perm[11];
  memcpy(perm, str, sizeof(str));
  permutation(perm, str, 1000000 - 1);
  printf("%s\n", perm);
  return 0;
}
