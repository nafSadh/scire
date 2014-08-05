/*Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return true.
*/

#include <vector>
#include <algorithm>
using namespace std;

namespace L33tC0d3
{
  namespace search_a_2d_matrix
  {
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
        return binary_search(mat[r].begin(), mat[r].end(), target);
      }

      bool searchMatrix(vector<vector<int> > &matrix, int target)
      {
        rowc = matrix.size();
        colc = matrix[0].size();
        mat = matrix;

        //find the row
        int row = searchForRow(0, rowc - 1, target);
        if (row<0) return false;
        return findInRow(row, target);
      }
    };
  }
}