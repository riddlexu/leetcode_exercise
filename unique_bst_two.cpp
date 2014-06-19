//https://oj.leetcode.com/problems/unique-binary-search-trees-ii/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  vector<TreeNode *> generateTrees(int n) {
    vector<TreeNode *> ans;
    for (int i = 1; i <= n; ++i){
      TreeNode *root = new TreeNode(i);
      for (int j = 1; j <= n; ++j){
        if (i != j){
          //insert(root,
          // i don't know how to do
          // need to think about it
        }
      }
    }
    return ans;
  }

  void insert(TreeNode *root, int n){
    if (root->val < n){
      if (root->left){
        insert(root->left, n);
      }
      else {
        TreeNode *element = new TreeNode(n);
        root->left = element;
      }
    }
    else {
      if (root->right){
        insert(root->right, n);
      }
      else {
        TreeNode *element = new TreeNode(n);
        root->right = element;
      }
    }
  }
};
