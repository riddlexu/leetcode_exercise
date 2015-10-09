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
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ans;
    if (root == NULL){
      return ans;
    }
    vector<int> left,right;
    left = inorderTraversal(root->left);
    
    for (size_t i = 0; i < left.size(); i++){
      ans.push_back(left[i]);
    }
    ans.push_back(root->val);
    right = inorderTraversal(root->right);
    for (size_t i = 0; i < right.size(); i++){
      ans.push_back(right[i]);
    }
    return ans;
  }

  vector<int> inorderTraversal_iter(TreeNode *root) {
    vector<int> ans;
    stack<TreeNode*> mystack;
    if (root == NULL){
      return ans;
    }
    while(true){
      if (root){
        mystack.push(root);
        root = root->left;
      }
      else if (!mystack.empty()){
        root = mystack.top();
        ans.push_back(root->val);
        mystack.pop();
        root = root->right;
      }
      else{
        break;
      }
    }
    return ans;
  }  
};


int main()
{
  Solution solution;
  TreeNode tree(1);
  TreeNode tree2(2);
  TreeNode* treepoint = &tree;
  treepoint->right = &tree2;
  vector<int> inorder = solution.inorderTraversal_iter(&tree);
  return 0;
}
