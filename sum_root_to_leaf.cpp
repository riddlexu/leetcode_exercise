//https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/

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
  int sumNumbers(TreeNode *root) {
    if (root == NULL){
      return 0;
    }
    sumNumbers_rec(root,0);
  }
  int sumNumbers_rec(TreeNode *root, int prev){
    int sum = prev*10 + root->val;
    if ((root->left == NULL) && (root->right == NULL)){
      return sum;
    }
    int ans = 0;
    if (root->left){
      ans = sumNumbers_rec(root->left,sum);
    }
    if (root->right){
      ans += sumNumbers_rec(root->right,sum);
    }
    return ans;
  }
};
