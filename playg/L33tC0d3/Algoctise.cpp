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

int main()
{
  while (true) {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
  }
}