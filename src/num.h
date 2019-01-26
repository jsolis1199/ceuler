#include <math.h>
#include <string.h>

unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (b) {return gcd(b, a % b);}
  else {return a;}
}

unsigned long long lcm(unsigned long long a, unsigned long long b) {
  return a * b / gcd(a, b);
}

unsigned long long factorial(unsigned long long n) {
  unsigned long long prod = 1;
  for (unsigned long long i = 0; i < n; i++) {prod *= i + 1;}
  return prod;
}

unsigned long long binom(unsigned long long n, unsigned long long m) {
  return factorial(n) / (factorial(m) * factorial(n - m));
}

long long llpowll(long long n, unsigned long long e) {
  if (e == 0) {return 1;}
  else if (e == 1) {return n;}
  else if ((e % 2) == 0) {return llpowll(n * n, e / 2);}
  else if (e % 2 == 1) {return n * llpowll(n * n, (e - 1) / 2);}
}

unsigned long long sum_of_powers(unsigned long long n, unsigned long long e) {
  if (e == 0) {return n;}
  else {
    unsigned long long sum = llpowll(n, e + 1);
    for (unsigned long long i = 0; i < e; i++) {
      unsigned long long summand = binom(e + 1, i) * sum_of_powers(n, i);
      if ((e + 1 - i) % 2) {sum -= summand;}
      else {sum += summand;}
    }
    return sum / (e + 1);
  }
}

unsigned long long factor(unsigned long long n) {
  if (n % 2 == 0) {
    return 2;
  }
  else if (n % 3 == 0) {
    return 3;
  }
  else {
    for (int k = 1; k <= sqrt(n) / 6; k++) {
      if (n % (6 * k - 1) == 0) {
        return 6 * k - 1;
      }
      else if (n % (6 * k + 1) == 0) {
        return 6 * k + 1;
      }
    }
  }
  return n;
}

int is_prime(unsigned long long n) {
  return (factor(n) == n);
}
