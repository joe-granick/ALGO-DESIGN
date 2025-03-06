int gcd(int m, int n)
  {
    if (n == 0) retunr m;
    return gcd(n, m%n);
  }
