//https://oj.leetcode.com/problems/validate-binary-search-tree/

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
  bool isValidBST(TreeNode *root) {
    if (root == NULL){
      return true;
    }
    int min, max;
    return balanced(root, min, max);
  }

  bool balanced(TreeNode *root, int &min, int &max){
    int lmin,lmax,rmin,rmax;
    bool left_balanced, right_balanced;

    min = root->val;
    max = root->val;
    if ((root->left == NULL) && (root->right == NULL)){
      return true;
    }
    if (root->left != NULL){
      left_balanced = balanced(root->left, lmin, lmax);
      if (!(left_balanced && (lmax < root->val))){
        return false;
      }
      min = lmin;
    }
    if (root->right != NULL){
      right_balanced = balanced(root->right, rmin, rmax);
      if (!(right_balanced && (rmin > root->val))){
        return false;
      }
      max = rmax;
    }
    return true;
  }
};
