#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>


using namespace std;
//* Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  void levelOrder(TreeNode *node, int level, vector<vector<int>>& v)
  {
    if (node == nullptr) return;
    if (v.size()<=level) {
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
int main()
{
  Solution s;
  TreeNode tn(2);
  s.levelOrder(&tn);
  return 0;
}