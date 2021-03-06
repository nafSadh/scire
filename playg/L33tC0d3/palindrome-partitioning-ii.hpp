/* Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut. */
#include <vector>
#include <string>

using namespace std;

namespace L33tC0d3
{
  namespace palindrome_partitioning_ii
  {
    class Solution
    {
     public:
      int minCut(string s)
      {
        if (s.empty()) return 0;
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        vector<int> d(n);
        for (int i = n - 1; i >= 0; i--) {
          d[i] = n - i - 1;
          for (int j = i; j<n; j++) {
            if (s[i] == s[j] && (j - i<2 || pal[i + 1][j - 1])) {
              pal[i][j] = true;
              if (j == n - 1)
                d[i] = 0;
              else if (d[j + 1] + 1<d[i])
                d[i] = d[j + 1] + 1;
            }
          }
        }
        return d[0];
      }
    };
  }
}