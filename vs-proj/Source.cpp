#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
  vector<vector<int>> mat;
  int rowc;
  int colc;
 public:
  int searchForRow(int low, int high, int target)
  {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (mat[mid][0] <= target && target <= mat[mid][colc - 1]) {
      return mid;
    }
    if (target<mat[mid][0]) {
      return searchForRow(low, mid - 1, target);
    } else {
      return searchForRow(mid + 1, high, target);
    }
  }

  bool findInRow(int r, int target)
  {
    return binary_search(mat[r].begin(),mat[r].end(), target);
  }

  bool searchMatrix(vector<vector<int> > &matrix, int target)
  {
    rowc = matrix.size();
    colc = matrix[0].size();
    mat = matrix;

    //find the row
    int row = searchForRow(0, rowc-1, target);
    if (row<0) return false;
    return findInRow(row, target);
  }
};

int main()
{
  vector<int> x {1};
  vector<int> y {3};
  vector<vector<int>> v;
  v.push_back(x);
  v.push_back(y);
  Solution s;
  cout << s.searchMatrix(v, 3);
  return 0;
}