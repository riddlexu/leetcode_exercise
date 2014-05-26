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
  vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > ans;
    if (root == NULL){
      return ans;
    }
    
    pair<TreeNode*,int> con = make_pair(root, 0);
    queue<pair<TreeNode*, int> > myqueue;
    myqueue.push(con);

    TreeNode* node;
    while(myqueue.empty() != true){
      node = mydeque.front();
      
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
  vector<vector<int> > levelorder = solution.levelOrder(&tree);
  return 0;
}

