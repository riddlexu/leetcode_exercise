//https://oj.leetcode.com/problems/pascals-triangle/

class Solution {
 public:
  vector<vector<int> > generate(int numRows) {
    vector<vector<int> > ans;
    if (numRows == 0){
      return ans;
    }
    vector<int> element;
    ans.push_back(element);
    ans[0].push_back(1);
    for (int i = 1; i < numRows; ++i){
      vector<int> temp;
      ans.push_back(temp);
      ans[i].push_back(1);
      for (int j = 1; j < i; ++j){
        ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
      }
      ans[i].push_back(1);
    }

    return ans;
  }
};
