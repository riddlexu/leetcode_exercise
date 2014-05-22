#include<iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    if (root == NULL){
      return true;
    }
    return isSameTree(root->left, root->right);
  }

  bool isSameTree(TreeNode *p, TreeNode *q) {
    bool ans;
    if (p == NULL){
      if (q == NULL){
        ans = true;
      }
      else{
        ans = false;
      }
      return ans;
    }

    if (q == NULL){
      return false;
    }
    return ((p->val == q->val) && isSameTree(p->left,q->right) && isSameTree(p->right, q->left));
  }

};


int main()
{
  Solution solution;
  TreeNode tree(1);
  TreeNode tree2(2);
  TreeNode* treepoint = &tree;
  treepoint->right = &tree2;
  cout << solution.isSymmetric(&tree) << endl;
  return 0;
}
