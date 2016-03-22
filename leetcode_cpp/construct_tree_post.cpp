//https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.empty()){
      return NULL;
    }
    return buildRecv(inorder,postorder,0,0,inorder.size());
  }
 private:
  TreeNode *buildRecv(vector<int> &inorder, vector<int> &postorder, unsigned int start_in, unsigned int start_post, int length){
    TreeNode* root = new TreeNode(postorder[start_post+length-1]);
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
      root->left = buildRecv(inorder,postorder,start_in, start_post,mid_loc - start_in);
    }

    if (length - mid_loc + start_in - 1 >0){
      root->right = buildRecv(inorder,postorder,mid_loc + 1,start_post + mid_loc - start_in, length - mid_loc + start_in - 1);
    }
    return root;
  }
};

int main()
{
  vector<int> postorder;
  vector<int> inorder;
  int n,temp;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> temp;
    inorder.push_back(temp);
  }
  for (int i = 0; i < n; i++){
    cin >> temp;
    postorder.push_back(temp);
  }
  Solution solution;
  TreeNode* tree = solution.buildTree(inorder,postorder);
  return 0;
}
