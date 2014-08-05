/*Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a <= b <= c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

namespace L33tC0d3
{
  namespace three_sum
  {
    class Solution
    {
     public:
      vector<vector<int> > threeSum(vector<int> &num)
      {
        vector<vector<int>> res;
        sort(num.begin(), num.end());

        int n = num.size();
        int target = 0;

        set<vector<int>> rset;
        for (int i = 0; i <= (n - 3); i++) {
          int a = num[i];
          int j = i + 1;
          int k = n - 1;
          while (j < k) {
            int d = a + num[j] + num[k];
            if (d == 0) {
              vector<int> v {a, num[j], num[k]};
              rset.insert(v);
            }
            if (d > 0) k--;
            else j++;
          }
        }
        for (auto it = rset.begin(); it != rset.end(); it++)
          res.push_back(*it);
        return res;
      }
    };

  }
}