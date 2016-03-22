//https://oj.leetcode.com/problems/plus-one/

class Solution {
 public:
  vector<int> plusOne(vector<int> &digits) {
    int increment = 1;
    vector<int> ans = digits;
    for (int i = digits.size() - 1; i >= 0; --i){
      ans[i] = digits[i] + increment;
      if (ans[i] >= 10){
        increment = 1;
        ans[i] = ans[i] % 10;
      }
      else {
        increment = 0;
      }
    }
    if (increment == 1){
      ans.insert(ans.begin(), 1);
    }
    return ans;
  }
};
