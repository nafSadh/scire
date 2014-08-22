/*Write a function to find the longest common prefix string amongst an array of strings. */
#include <vector>
#include <string>

namespace L33tC0d3
{
  namespace longest_common_prefix
  {
    using namespace std;
    class Solution
    {
     public:
      string longestCommonPrefix(vector<string> &strs)
      {
        int n = strs.size();
        if (n<1) return "";
        if (n == 1)return strs[0];
        int i = 0;
        bool run = true;
        while (run) {
          if (i >= strs[0].length()) {
            run = false;
            break;
          }
          char c = strs[0][i];
          for (int j = 1; j<n; j++) {
            if (i >= strs[j].length() || c != strs[j][i]) {
              run = false;
              break;
            }
          }
          if (run)i++;
        }
        return strs[0].substr(0, i);
      }
    };
  }
}