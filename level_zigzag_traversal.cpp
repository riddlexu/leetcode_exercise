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

    pair<TreeNode*, int> temp;
    int level = 0;
    while(myqueue.empty() != true){
      temp = myqueue.front();
      if (temp.second == level){
        level++;
        vector<int> newele;
        ans.push_back(newele);
      }
      ans[temp.second].push_back((temp.first)->val);


      if ((temp.first)->left != NULL){
        myqueue.push(make_pair((temp.first)->left, temp.second + 1));
      }
      if ((temp.first)->right != NULL){
        myqueue.push(make_pair((temp.first)->right, temp.second + 1));
      }
      myqueue.pop();
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

