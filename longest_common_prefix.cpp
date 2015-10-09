//https://oj.leetcode.com/problems/longest-common-prefix/

class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    string ans = "";
    if (strs.size() == 0){
      return ans;
    }
    if (strs.size() == 1){
      return strs[0];
    }
    char tmp;
    for (int i = 0; i < strs[0].size(); ++i){
      tmp = strs[0][i];
      for (int j = 1; j < strs.size(); ++j){
        if ((i >= strs[j].size()) || (tmp != strs[j][i])){
          return ans;
        }
      }
      ans.push_back(tmp);
    }
    return ans;
  }
};
