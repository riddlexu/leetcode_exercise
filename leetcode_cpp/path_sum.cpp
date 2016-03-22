//https://oj.leetcode.com/problems/path-sum/

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
  bool hasPathSum(TreeNode *root, int sum) {
    if (root == NULL){
      return false;
    }
    return hasEqualSum(root, 0, sum);
  }
  bool hasEqualSum(TreeNode *root, int now, int sum){
    if (root == NULL){
      return (now == sum);
    }

    now = now + root->val;
    if ((root->left == NULL) && (root->right == NULL)){
      return (now == sum);
    }

    if (root->left){
      if (hasEqualSum(root->left, now, sum)){
        return true;
      }
    }
    if (root->right){
      if (hasEqualSum(root->right, now, sum)){
        return true;
      }
    }
    return false;
  }
};
