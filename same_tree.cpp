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
    bool isSameTree(TreeNode *p, TreeNode *q) {
      bool ans;
      if (p == NULL){
        if (q == NULL){
          ans = true;
        }
        else{
          ans = false;
        }
        return ans;
      }

      if (q == NULL){
        return false;
      }

      return ((p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right, q->right));
    }
};

int main()
{
  Solution solution;
  TreeNode tree1(1);
  TreeNode tree2(1);
  cout << solution.isSameTree(&tree1, &tree2) << endl;
  return 0;
}
