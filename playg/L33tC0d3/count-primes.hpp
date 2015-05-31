#include <vector>
using namespace std;
namespace L33tC0d3
{
  class CountPrimes
  {
   public:
    int countPrimes(int n)
    {
      if (n <= 2) return 0;
      vector<int> primes;
      primes.push_back(2);
      for (int i = 3; i < n; i += 2) {
        bool isp = true;
        int lim = sqrt(n);
        for (int j = 0; j < primes.size() && primes[j] <= lim; j++) {
          if (i%primes[j] == 0) {
            isp = false;
            break;
          }
        }
        if (isp)primes.push_back(i);
      }
      return primes.size();
    }
  };
}