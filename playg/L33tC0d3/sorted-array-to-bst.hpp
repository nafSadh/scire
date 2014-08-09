#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

namespace L33tC0d3
{
  namespace sorted_array_to_bst
  {
    /**
    * Definition for binary tree*/
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution
    {
      void toBST(TreeNode* &node, vector<int>&num, int low, int high)
      {
        if (low > high) return;
        int mid = (low + high) / 2;
        node = new TreeNode(num[mid]);
        toBST(node->left, num, low, mid - 1);
        toBST(node->right, num, mid + 1, high);
      }
     public:
      TreeNode *sortedArrayToBST(vector<int> &num)
      {
        TreeNode *root = NULL;
        toBST(root, num, 0, num.size() - 1);
        return root;
      }
    };
  }
}