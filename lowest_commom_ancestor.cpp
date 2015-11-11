//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * 
 };
*/
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val == q->val) {
      return p;
    }
    if (root == NULL) {
      return NULL;
    }
    if (p->val == root->val) {
      return root;
    }
    if (q->val == root->val) {
      return root;
    }
    bool a = IsInTree(root->left, p);
    bool b = IsInTree(root->left, q);
    if (a && b) {
      return lowestCommonAncestor(root->left, p, q);
    }
    if (a || b) {
      return root;
    }
    return lowestCommonAncestor(root->right, p, q);
  }
  bool IsInTree(TreeNode* root, TreeNode*p) {
    if (p == NULL) {
      return true;
    }
    if (root == NULL) {
      return false;
    }
    return (root->val == p->val) || IsInTree(root->left, p) || IsInTree(root->right, p);     
  }
};
