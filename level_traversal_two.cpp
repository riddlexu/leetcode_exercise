#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
        
  }
};

int main()
{
  Solution solution;
  TreeNode tree(1);
  TreeNode tree2(2);
  TreeNode* treepoint = &tree;
  treepoint->right = &tree2;
  vector<vector<int> > levelorder = solution.levelOrderBottom(&tree);
  return 0;
}
