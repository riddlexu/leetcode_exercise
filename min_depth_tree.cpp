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
        
  }
};


int main()
{
  Solution solution;
  TreeNode tree(2);
  cout << solution.minDepth(&tree) << endl;
  return 0;
}
