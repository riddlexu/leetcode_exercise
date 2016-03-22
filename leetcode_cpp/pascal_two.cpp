//https://oj.leetcode.com/problems/pascals-triangle-ii/

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> ans;
    ans.push_back(1);
    if (rowIndex == 0){
      return ans;
    }
    ans.push_back(1);
    int prev_buf,this_buf;
    for (int i = 2; i <= rowIndex; ++i){
      prev_buf = ans[0];
      for (int j = 1; j < i; ++j){
        this_buf = prev_buf + ans[j];
        prev_buf = ans[j];
        ans[j] = this_buf;
      }
      ans.push_back(1);
    }
  }
};
