/*Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?*/
#include <vector>
using namespace std;
namespace L33tC0d3
{
  namespace binary_tree_postorder_traversal
  {
    /**/
    //Definition for binary tree
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution
    {
      vector<int> v;
      void postTrav(TreeNode *root)
      {
        if (root == nullptr) return;
        postTrav(root->left);
        postTrav(root->right);
        v.push_back(root->val);
      }
     public:
      vector<int> postorderTraversal(TreeNode *root)
      {
        v.clear();
        postTrav(root);
        return v;
      }
    };
  }
}