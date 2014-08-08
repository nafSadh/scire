/* Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
    */

#include <climits>
using namespace std;

namespace L33tC0d3
{
  namespace validate_binary_search_tree
  {
    // Definition for binary tree
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    class Solution
    {
      bool isBST(TreeNode *root, int low, int high) const
      {
        if (root == nullptr) return true;
        if (low<root->val && root->val<high) {
          return isBST(root->left, low, root->val)
                 && isBST(root->right, root->val, high);
        }
        return false;
      }
     public:
      bool isValidBST(TreeNode *root)
      {
        return isBST(root, INT_MIN, INT_MAX);
      }
    };
  }
}