/*
Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/
namespace L33tC0d3
{
  namespace same_tree
  {
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    class Solution
    {
     public:
      bool isSameTree(TreeNode *p, TreeNode *q)
      {
        if (p == nullptr || q == nullptr) return (p == q);

        return (p->val == q->val)
               && isSameTree(p->left, q->left)
               && isSameTree(p->right, q->right);
      }
    };
  }
}