#include<vector>
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
};

int main()
{
  Solution solution;
  TreeNode tree(2);
  vector<int> preorder = solution.preorderTraversal(&tree);
  return 0;
}
