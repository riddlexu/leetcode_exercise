//https://oj.leetcode.com/problems/path-sum-ii/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > ans;
    if (root == NULL){
      return ans;
    }
    vector<int> init;
    return pathSum_rec(root,init, 0,sum);
  }
  vector<vector<int> > pathSum_rec(TreeNode *root, vector<int> now_element, int now, int sum){
    vector<vector<int> > ans;
    if (root == NULL){
      if (now == sum){
        ans.push_back(now_element);
      }
      return ans;
    }

    now = now + root->val;
    now_element.push_back(root->val);

    if ((root->left == NULL) && (root->right == NULL)){
      if (now == sum){
        ans.push_back(now_element);
      }
      return ans;
    }
    
    if (root->left){
      vector<vector<int> > left_res = pathSum_rec(root->left,now_element,now,sum);
      for (int i = 0; i < left_res.size(); ++i){
        ans.push_back(left_res[i]);
      }
    }
    if (root->right){
      vector<vector<int> > right_res = pathSum_rec(root->right,now_element,now,sum);
      for (int i = 0; i < right_res.size(); ++i){
        ans.push_back(right_res[i]);
      }
    }
    return ans;
  }
};
