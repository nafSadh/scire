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

int power(int x, int y)
{
  if (y == 0) return 1;

  int yy = y;
  int i = 0;
  int res = 1;
  int p = x;
  while (yy > 0) {
    if (yy & 1 == 1) {
      res *= p;
    }
    yy = yy >> 1;
    p *= p;
  }

  return res;
}

int main()
{
  while (true) {
    int a, b;
    cin >> a >> b;
    cout << power(a, b) << " | "<<pow(a,b) << endl;
  }
}