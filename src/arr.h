#include <string.h>
#include <stdlib.h>

#include "num.h"

void sieve_of_eratosthenes(char sieve[], unsigned long len) {
  memset(sieve + 2, 1, len - 2); 
  unsigned long i = 2;
  while (i < len) {
    while (!sieve[i]) {
      i++;
    }   
    for (unsigned long j = 2*i; j < len; j += i) {
      sieve[j] = 0;
    }   
    i++;
  }
}

void aprintd(int arr[], int len) {
  printf("{");
  for (int i = 0; i < len - 1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("%d}\n", arr[len - 1]);
}

void aprintllu(unsigned long long arr[], int len) {
  printf("{");
  for (int i = 0; i < len - 1; i++) {
    printf("%llu, ", arr[i]);
  }
  printf("%llu}\n", arr[len - 1]);
}

void range(unsigned long long arr[], unsigned long long i, unsigned long long j) {
  for (unsigned long long k = i; k < j; k++) {arr[k - i] = k;}
}

unsigned long product(unsigned long arr[], int len) {
  unsigned long n = 1;
  for (int i = 0; i < len; i++) {n *= arr[i];}
  return n;
}

unsigned long long min(unsigned long long arr[], int len) {
  unsigned long n = arr[0];
  for (int i = 1; i < len; i++) {if (arr[i] < n) {n = arr[i];}}
  return n;
}

unsigned long mindex(unsigned long long arr[], int len) {
  unsigned long n = 0;
  for (int i = 1; i < len; i++) {if (arr[i] < arr[n]) {n = i;}}
  return n;
}

unsigned long long max(unsigned long long arr[], int len) {
  unsigned long long n = 0;
  for (int i = 1; i < len; i++) {if (arr[i] > n) {n = arr[i];}}
  return n;
}

unsigned long maxdex(unsigned long long arr[], int len) {
  unsigned long n = 0;
  for (int i = 1; i < len; i++) {if (arr[i] > arr[n]) {n = i;}}
  return n;
}

unsigned long long agcd(unsigned long long arr[], int len) {
  if (len == 1) {return arr[0];}
  else if (len == 2) {return gcd(arr[0], arr[1]);}
  else if (len > 2) {
    int half = len / 2;
    unsigned long long prefix[half], suffix[len - half];
    memcpy(prefix, arr, half * sizeof(unsigned long long));
    memcpy(suffix, arr + half, (len - half) * sizeof(unsigned long long));
    return gcd(agcd(prefix, half), agcd(suffix, len - half));
  }
  else {return gcd(arr[0], arr[1]);}
}

unsigned long long alcm(unsigned long long arr[], int len) {
  if (len == 1) {return arr[0];}
  else if (len == 2) {return lcm(arr[0], arr[1]);}
  else if (len > 2) {
    int half = len / 2;
    unsigned long long prefix[half], suffix[len - half];
    memcpy(prefix, arr, half * sizeof(unsigned long long));
    memcpy(suffix, arr + half, (len - half) * sizeof(unsigned long long));
    return lcm(alcm(prefix, half), alcm(suffix, len - half));
  }
  else {return lcm(arr[0], arr[1]);}
}
