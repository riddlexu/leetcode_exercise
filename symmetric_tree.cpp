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
  bool isSymmetric(TreeNode *root) {
    
  }
};


int main()
{
  Solution solution;
  TreeNode tree(1);
  TreeNode tree2(2);
  TreeNode* treepoint = &tree;
  treepoint->right = &tree2;
  cout << solution.isSymmetric(tree) << endl;
  return 0;
}
