#include<iostream>
#include<stack>
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
    return isSymmetricTree(root->left, root->right);
  }

  bool isSymmetricTree(TreeNode *p, TreeNode *q) {
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
    return ((p->val == q->val) && isSymmetricTree(p->left,q->right) && isSymmetricTree(p->right, q->left));
  }

  bool isSymmetric_iter(TreeNode *root) {
    if (root == NULL){
      return true;
    }

    stack<TreeNode*> left_stack, right_stack;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    if (!visit_symmetric_bottom(left, right, left_stack, right_stack)){
      return false;
    }

    while(left_stack.size() > 0){
      left = left_stack.top();
      right = right_stack.top();
      left_stack.pop();
      right_stack.pop();
      if (!visit_symmetric_bottom(left, right, left_stack, right_stack)){
        return false;
      }
    }
    return true;
  }

  bool visit_symmetric_bottom(TreeNode* left, TreeNode* right, stack<TreeNode*> &left_stack, stack<TreeNode*> &right_stack){
    while((left != NULL) && (right != NULL)){
      if (left->val != right->val){
        return false;
      }
      left_stack.push(left->right);
      right_stack.push(right->left);
      left = left->left;
      right = right->right;
    }
    if ((left != NULL) || (right != NULL)){
      return false;
    }
    return true;
  }

};


int main()
{
  Solution solution;
  TreeNode tree(1);
  TreeNode tree2(2);
  TreeNode* treepoint = &tree;
  treepoint->right = &tree2;
  cout << solution.isSymmetric_iter(&tree) << endl;
  return 0;
}
