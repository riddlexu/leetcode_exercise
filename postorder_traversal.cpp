#include<vector>
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
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ans;
    if (root == NULL){
      return ans;
    }
    vector<int> left,right;
    left = postorderTraversal(root->left);
    right = postorderTraversal(root->right);
    for (size_t i = 0; i < left.size(); i++){
      ans.push_back(left[i]);
    }
    for (size_t i = 0; i < right.size(); i++){
      ans.push_back(right[i]);
    }
    ans.push_back(root->val);
    return ans;
  }
  
  vector<int> postorderTraversal_iter(TreeNode *root){
    vector<int> ans;
    stack<TreeNode*> mystack;
    vector<int> left;
    TreeNode* top;
    if (root != NULL){
      mystack.push(root);
    }
    while(!(mystack.empty())){
      top = mystack.top();
      if ((top->left != root) && (top->right != root)){
        goto_hlvfl(mystack);
      }
      root = mystack.top();
      mystack.pop();
      ans.push_back(root->val);
    }
    return ans;
  }
  void goto_hlvfl(stack<TreeNode*> &mystack){
    TreeNode* node = mystack.top();
    while(node->left || node->right){
      if (node->left){
        if (node->right){
          mystack.push(node->right);
        }
        mystack.push(node->left);
      }
      else {
        mystack.push(node->right);
      }
      node = mystack.top();
    }
  }
};

int main()
{
  Solution solution;
  TreeNode tree(1);
  TreeNode tree2(2);
  TreeNode* treepoint = &tree;
  treepoint->right = &tree2;
  vector<int> postorder = solution.postorderTraversal_iter(&tree);
  return 0;
}

