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
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ans;
    if (root == NULL){
      return ans;
    }
    ans.push_back(root->val);
    vector<int> left,right;
    left = preorderTraversal(root->left);
    right = preorderTraversal(root->right);
    for (size_t i = 0; i < left.size(); i++){
      ans.push_back(left[i]);
    }
    for (size_t i = 0; i < right.size(); i++){
      ans.push_back(right[i]);
    }

    return ans;
  }
  
  vector<int> preorderTraversal_iter(TreeNode *root){
    vector<int> ans;
    stack<TreeNode*> mystack;
    vector<int> left;
    TreeNode* top;
    
    visit_bottom(root,mystack,ans);
    while(mystack.size() > 0){
      top = mystack.top();
      mystack.pop();
      visit_bottom(top,mystack,ans);
    }
    return ans;
  }
  void visit_bottom(TreeNode *root, stack<TreeNode*> &mystack, vector<int> &preorder){
    while(root != NULL){
      preorder.push_back(root->val);
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
  vector<int> preorder = solution.preorderTraversal_iter(&tree);
  return 0;
}
