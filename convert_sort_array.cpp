
 
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
 public:
  TreeNode *sortedArrayToBST(vector<int> &num) {
    return convert(num,0,num.size()); 
  }
  TreeNode *convert(vector<int> &num, int start, int length){
    if (length <= 0){
      return NULL;
    }
    if (length == 1){
      TreeNode* p = new TreeNode(num[start]);
      return p;
    }
    if (length == 2){
      TreeNode* p = new TreeNode(num[start]);
      TreeNode* q = new TreeNode(num[start+1]);
      if (p->val <= q->val){
        p->right = q;
      }
      else {
        p->left = q;
      }
      return p;
    }
    int mid = start + length / 2;
    TreeNode* root = new TreeNode(num[mid]);
    TreeNode* p = convert(num,start,mid - start);
    TreeNode* q = convert(num,mid+1,length - (mid - start) - 1);
    root->left = p;
    root->right = q;
    return root;        
  }
};
