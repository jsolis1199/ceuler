#!/usr/bin/tcc -run

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char buff[51], str[52];
  char * end;
  long double sum = 0;
  FILE * file;
  file = fopen("../problem-13.txt", "r");
  while (fgets(buff, 51, file)) {
    if (buff[0] == '\n') {continue;}
    strncpy(str, buff, 10*sizeof(char));
    str[10] = '.';
    strcpy(str + 11, buff + 10);
    sum += strtold(str, &end);
  }
  fclose(file);
  char ans[11];
  snprintf(ans, 11, "%llf", sum);
  printf("%s\n", ans);
  return 0;
}
