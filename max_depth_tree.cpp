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
  int maxDepth(TreeNode *root) {
    if (root == NULL){
      return 0;
    }
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    if (l > r){
      return l + 1;
    }
    else {
      return r + 1;
    }
    return 0;
  }
};

int main()
{
  Solution solution;
  TreeNode tree(2);
  cout << solution.maxDepth(&tree) << endl;
  return 0;
}
