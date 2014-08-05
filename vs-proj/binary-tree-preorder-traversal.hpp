/*Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?*/
#include <vector>
using namespace std;
namespace L33tC0d3
{
  namespace binary_tree_preorder_traversal
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
      void preTrav(TreeNode *root)
      {
        if (root == nullptr) return;
        v.push_back(root->val);
        preTrav((root)->left);
        preTrav((root)->right);
      }
     public:
      vector<int> preorderTraversal(TreeNode *root)
      {
        v.clear();
        preTrav(root);
        return v;
      }
    };
  }
}