/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock during the
entire period),
design an algorithm to find the maximum profit.

NOTE: this problem talks about 1 buy and 1 sale during the entire sales, not per day
*/

#include <vector>
using namespace std;

namespace L33tC0d3
{
  namespace best_time_to_buy_and_sell_stock
  {
    class Solution
    {
     public:
      int maxProfit(vector<int> &prices)
      {
        int n = prices.size();
        if (n<2) return 0;
        int minv = prices[0], maxv = prices[n - 1];
        int profit = 0;
        vector<int> minb(n), maxa(n);
        for (int i = 0; i<n; i++) {
          if (minv >(prices[i]))
            minv = prices[i];
          minb[i] = minv;
          if (maxv<(prices[n - i - 1]))
            maxv = prices[n - i - 1];
          maxa[n - i - 1] = maxv;
        }
        for (int i = 0; i<n; i++) {
          if (maxa[i] - minb[i] > profit)
            profit = maxa[i] - minb[i];
        }
        return profit;
      }
    };

  }
}