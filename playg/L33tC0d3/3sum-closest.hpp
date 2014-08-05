/*

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace L33tC0d3
{
  namespace three_sum_closest
  {
    class Solution
    {
     public:
      int threeSumClosest(vector<int> &num, int target)
      {
        int delta = INT_MAX;
        int close = INT_MAX;

        sort(num.begin(), num.end());
        int n = num.size();

        for (int i = 0; i <= (n - 3); i++) {
          int a = num[i];
          int j = i + 1;
          int k = n - 1;
          while (j < k) {
            int d = a + num[j] + num[k];
            if (abs(d - target) < delta) {
              close = d;
              delta = abs(d - target);
            }
            if (d > target) k--;
            else j++;
          }
        }
        return close;
      }
    };
  }
}