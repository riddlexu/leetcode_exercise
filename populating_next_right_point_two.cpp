//https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
 public:
  void connect(TreeLinkNode *root) {
    if (root == NULL){
      return;
    }
    TreeLinkNode* left_most = root;
    TreeLinkNode* now = root;
    bool hasnext;
    TreeLinkNode* prev;
    do{
      now = left_most;
      prev = NULL;
      do{
        if (now->left && now->right){
          if (prev){
            prev->next = now->left;
          }
          else{
            left_most = now->left;
          }
          (now->left)->next = now->right;
          prev = now->right;
        }
        else if (now->left){
          if (prev){
            prev->next = now->left;
          }
          else{
            left_most = now->left;
          }
          prev = now->left;
        }
        else if (now->right){
          if (prev){
            prev->next = now->right;
          }
          else{
            left_most = now->right;
          }
          prev = now->right;
        }
        now = now->next;
      }
      while(now);
    }
    while(prev);
  }
};
