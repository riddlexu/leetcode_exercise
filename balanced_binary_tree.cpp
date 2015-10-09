//https://oj.leetcode.com/problems/balanced-binary-tree/

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
  bool isBalanced(TreeNode *root) {
    int ans = balanced_height(root);
    return (ans != -1);
  }

  int balanced_height(TreeNode *root){
    if (root == NULL){
      return 0;
    }
    int left_height = balanced_height(root->left);
    if (left_height == -1){
      return -1;
    }
    int right_height = balanced_height(root->right);
    if ((right_height == -1) || (abs(left_height - right_height) > 1)){
      return -1;
    }
    return 1 + std::max(left_height, right_height);
  }
};
