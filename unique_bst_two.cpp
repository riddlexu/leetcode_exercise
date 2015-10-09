//https://oj.leetcode.com/problems/unique-binary-search-trees-ii/

#include<vector>
#include<stdlib.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
 public:
  vector<TreeNode *> generateTrees(int n) {
    if (n <= 0){
      vector<TreeNode *> ans;
      ans.push_back(NULL);
      return ans;
    }
    return generateBST(1,n);
  }

  vector<TreeNode *> generateBST(int start, int end){
    vector<TreeNode *> ans;
    TreeNode* mid;
    if (start == end){
      mid = new TreeNode(start);
      ans.push_back(mid);
      return ans;
    }
      
    for (int i = start; i <= end; ++i){
      vector<TreeNode *> left,right;
      if (i != start){
        left = generateBST(start,i-1);
      }
      if (i != end){
        right = generateBST(i+1,end);
      }
      if (i == start){
        for (int j = 0; j < right.size(); j++){
          mid = new TreeNode(i);
          mid->right = right[j];
          ans.push_back(mid);
        }
      }
      else if (i == end){
        for (int j = 0; j < left.size(); j++){
          mid = new TreeNode(i);
          mid->left = left[j];
          ans.push_back(mid);
        }
      }
      else {
        for(int j = 0; j < left.size(); j++){
          for (int k = 0; k < right.size(); k++){
            mid = new TreeNode(i);
            mid->left = left[j];
            mid->right = right[k];
            ans.push_back(mid);
          }
        }
      }
      
    }
    return ans;
  }
};

