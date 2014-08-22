/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

3
/ \
9  20
/  \
15   7

return its level order traversal as:

[
[3],
[9,20],
[15,7]
]

*/
#include<vector>

namespace L33tC0d3
{
  namespace binary_tree_level_order_traversal
  {
    using namespace std;
    /** Definition for binary tree*/
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    class Solution
    {
      void levelOrder(TreeNode *node, int level, vector<vector<int>>& v)
      {
        if (node == nullptr) return;
        if (v.size() <= level) {
          v.push_back(vector<int>());
        }
        v[level].push_back(node->val);
        levelOrder(node->left, level + 1, v);
        levelOrder(node->right, level + 1, v);
      }
     public:
      vector<vector<int> > levelOrder(TreeNode *root)
      {
        vector<vector<int>> v;
        levelOrder(root, 0, v);
        return v;
      }
    };
  }
}