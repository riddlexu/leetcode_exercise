//https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/

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
  int maxPathSum(TreeNode *root) {
    int res;
    return maxPathSum_rec(root ,res);
  }
  int maxPathSum_rec(TreeNode *root, int &res){
    if (root == NULL){
      return 0;
    }
    int ans = root->val;
    int lres = 0;
    int rres = 0;
    if (root->left){
      ans = std::max(ans,maxPathSum_rec(root->left,lres));
    }
    if (root->right){
      ans = std::max(ans,maxPathSum_rec(root->right,rres));
    }
    res = std::max(root->val, std::max(root->val + lres, root->val + rres));
    ans = std::max(ans,std::max(res,root->val + lres + rres));
    return ans;
  }
};
