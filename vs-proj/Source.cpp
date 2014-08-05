#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
      while (j<k) {
        int d = a + num[j] + num[k];
        if (abs(d - target)<delta) {
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

int main()
{
  vector<int> x {0, 2, 1, -3};
  Solution s;
  cout << s.threeSumClosest(x, 1);
  return 0;
}