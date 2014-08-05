/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include <vector>
#include <algorithm>
using namespace std;

namespace L33tC0d3
{
  namespace two_sum
  {
    class Solution
    {
     public:
      vector<int> twoSum(vector<int> &numbers, int target)
      {
        vector<int> v;
        for (int i = 0; i<numbers.size(); i++) {
          v.push_back(numbers[i]);
        }
        sort(v.begin(), v.end());
        bool done = false;
        int a, b;
        for (int j = 0; j<v.size() & !done; j++) {
          if (binary_search(v.begin(), v.end(), target - v[j])) {
            done = true;
            a = v[j];
            b = target - v[j];
          }
        }
        vector<int> res;
        for (int k = 0; k<numbers.size() && res.size()<2; k++) {
          if (numbers[k] == a || numbers[k] == b) {
            res.push_back(k + 1);
          }
        }
        return res;
      }
    };
  }
}