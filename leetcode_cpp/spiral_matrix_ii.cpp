//https://oj.leetcode.com/problems/spiral-matrix-ii/

class Solution {
 public:
  vector<vector<int> > generateMatrix(int n) {
    int level = n / 2;
    vector<vector<int> > ans;
    if(n == 0){
      return ans;
    }
    for(int i = 0; i < n; i++){
      vector<int> tmp;
      for(int j = 0; j < n; j++){
        tmp.push_back(0);
      }
      ans.push_back(tmp);
    }
    int now = 0;
    for(int i = 0; i < level; i++){
      for(int j = i; j < n - i; j++){
        now++;
        ans[i][j] = now;
      }
      for(int j = i + 1; j < n - i - 1; j++){
        now++;
        ans[j][n - 1 - i] = now;
      }
      for(int j = n - i - 1; j >= i; j--){
        now++;
        ans[n - 1 - i][j] = now;
      }
      for(int j = n - i - 2; j >= i + 1; j--){
        now++;
        ans[j][i] = now;
      }
    }
        
    if(n % 2 != 0){
      ans[level][level] = n*n;
    }
        
    return ans;
  }
};
