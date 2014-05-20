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
    TreeNode* top,x;
    if (root != NULL){
      mystack.push(root);
    }
    while(!(mystack.empty())){
      top = mystack.top();
      if (top->left != root){
        goto_hlvfl(mystack);
      }
      root = mystack.top();
      mystack.pop();
      ans.push(root->val);
    }
    return ans;
  }
  void goto_hlvfl(TreeNode *root, stack<TreeNode*> &mystack, vector<int> &postorder){
    while(root != NULL){
      postorder.push_back(root->val);
      if (root->right != NULL){
        mystack.push(root->right);
      }
      root = root->left;
    }
  }
};

int main()
{
  Solution solution;
  TreeNode tree(2);
  vector<int> postorder = solution.postorderTraversal_iter(&tree);
  return 0;
}

