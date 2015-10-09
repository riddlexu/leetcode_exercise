//https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
//use reference to overcome memory limit exceed
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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (inorder.empty()){
      return NULL;
    }
    return buildRecv(preorder,inorder,0,0,inorder.size());
  }
 private:
  TreeNode *buildRecv(vector<int> &preorder, vector<int> &inorder, unsigned int start_pre, unsigned int start_in, int length){
    TreeNode* root = new TreeNode(preorder[start_pre]);
    if (length == 1){
      return root;
    }
    
    int mid_loc;
    for (unsigned int i = start_in; i < start_in + length; i++){
      if (inorder[i] == root->val){
        mid_loc = i;
        break;
      }
    }
    if (mid_loc - start_in > 0){
      root->left = buildRecv(preorder, inorder, start_pre+1,start_in,mid_loc - start_in);
    }
    if (length - mid_loc + start_in - 1 > 0){
      root->right = buildRecv(preorder, inorder, start_pre + 1 + mid_loc - start_in, mid_loc + 1, length - mid_loc + start_in - 1);
    }
    return root;
  }
};

int main()
{
  vector<int> preorder;
  vector<int> inorder;
  int n,temp;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> temp;
    preorder.push_back(temp);
  }
  for (int i = 0; i < n; i++){
    cin >> temp;
    inorder.push_back(temp);
  }
  Solution solution;
  TreeNode* tree = solution.buildTree(preorder,inorder);
  return 0;
}
