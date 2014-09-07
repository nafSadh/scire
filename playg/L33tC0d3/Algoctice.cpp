#include <iostream>
#include <cstdint>
using namespace std;
/**
\gcd(a,a) = a
\gcd(a,b) = \gcd(a - b,b)\quad, if a > b
\gcd(a,b) = \gcd(a, b-a)\quad, if b > a
*/
int gcd(int a, int b)
{
  if (a == b) return a;
  else if (a > b) return gcd(a - b, b);
  else return gcd(a, b - a);
}

double power(int x, int y)
{
  if (x == 1 || x == 0) return x;
  if (y < 0) return 1/power(x,-y);
  if (y == 0) return 1;

  int yy = y;
  double p = x;
  double res = 1;

  while (yy > 0) {
    if (yy & 1) {
      res *= p;
    }
    yy = yy >> 1;
    p *= p;
  }

  return res;
}

bool isLittleEndian()
{
  int i = 1;
  char *ptr = (char*) &i;
  return (bool)(*ptr);
}

int countOnesInNumberBits1(int x)
{
  int c = 0;
  while (x > 0) {
    if (x & 1) c++;
    x = x >> 1;
  }
  return c;
}

int countOnesInNumberBits(int x)
{
  int c=0;
  while (x != 0) {
    x = x & (x - 1);
    c++;
  }
  return c;
}

int main()
{
  while (true) {
    int a, b;
    cin >> a;
    cout << countOnesInNumberBits(a) << endl;
  }

  return 0;
}