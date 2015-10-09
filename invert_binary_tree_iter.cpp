//https://leetcode.com/problems/invert-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == NULL){
      return NULL;
    }
    stack<TreeNode*> mystack;
    mystack.push(root);
    while(!mystack.empty()){
      TreeNode* parent = mystack.top();
      mystack.pop();
      swap(parent->left, parent->right);
      if(parent->left){
        mystack.push(parent->left);
      }
      if(parent->right){
        mystack.push(parent->right);
      }
    }
    return root;
  }
};
