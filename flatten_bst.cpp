//https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
  void flatten(TreeNode *root) {
    flatten_rec(root);
  }
  TreeNode* flatten_rec(TreeNode *root){
    if (root == NULL){
      return NULL;
    }
    TreeNode* right_end = NULL;
    if (root->right != NULL){
      right_end = flatten_rec(root->right);
    }
    TreeNode* left_end = NULL;
    if (root->left != NULL){
      left_end = flatten_rec(root->left);
      left_end->right = root->right;
      root->right = root->left;
      root->left = NULL;
    }
    if ((left_end == NULL) && (right_end == NULL)){
      return root;
    }
    else if (right_end == NULL){
      return left_end;
    }
    else {
      return right_end;
    }
  }
};
