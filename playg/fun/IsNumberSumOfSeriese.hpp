#include <cmath>

template<typedef inttype>
inttype IsNumberSumOfSeriese(inttype n)
{
  inttype x = (inttype)sqrt(2.0*n);
  inttype xsum = (x)*(x + 1) / 2;
  if (xsum == n) {
    return x;
  } else {
    return 0;
  }
}