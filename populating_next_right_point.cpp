//https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/

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
    while(left_most->left){
      do{
        (now->left)->next = now->right;
        if (now->next){
          (now->right)->next = (now->next)->left;
        }
        now = now->next;
      }
      while(now);
      left_most = left_most->left;
      now = left_most;
    }
  }
};
