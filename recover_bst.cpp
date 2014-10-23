//https://oj.leetcode.com/problems/recover-binary-search-tree/

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
  TreeNode* sol1;
  TreeNode* sol2;
  TreeNode* pre;
  void recoverTree(TreeNode *root) {
    sol1 = NULL;
    sol2 = NULL;
    pre = NULL;
    midTravel(root);
    swap(sol1->val,sol2->val);
  }
  void midTravel(TreeNode* root){
    if(root->left){
      midTravel(root->left);
    }
    if(pre){
      if(pre->val > root->val){
        if(sol1){
          sol2 = root;
        }
        else{
          sol1 = pre;
          sol2 = root;
        }
      }
    }
    pre = root;
    if(root->right){
      midTravel(root->right);
    }
  }
};
