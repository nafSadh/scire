#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include "../playg/L33tC0d3/Anagrams.hpp"


using namespace std;
class Solution
{
 public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    int minv = 0, maxv = 0;
    int profit = 0;
    vector<int> minb(n), maxa(n);
    for (int i = 0; i<n; i++) {
      if (minv >(prices[i]))
        minv = prices[i];
      minb[i] = minv;
      if (maxv<(prices[n - i - 1]))
        maxv = prices[n - i - 1];
      maxa[n - i-1] = maxv;
    }
    for (int i = 0; i<n; i++) {
      if (maxa[i] - minb[i] > profit)
        profit = maxa[i] - minb[i];
    }
    return profit;
  }
};

int main()
{
  vector<int> list = {1,2,4};
  Solution s;
  cout << s.maxProfit(list);

  return 0;
}