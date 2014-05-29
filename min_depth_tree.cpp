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
  int minDepth(TreeNode *root) {
    if (root == NULL){
      return 0;
    }
    if ((root->left == NULL) && (root->right == NULL)){
      return 1;
    }
    if (root->left == NULL){
      return 1 + minDepth(root->right);
    }
    if (root->right == NULL){
      return 1 + minDepth(root->left);
    }
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if (l < r){
      return l + 1;
    }
    else {
      return r + 1;
    }
  }
};


int main()
{
  Solution solution;
  TreeNode tree(2);
  cout << solution.minDepth(&tree) << endl;
  return 0;
}
