//https://oj.leetcode.com/problems/gray-code/

class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> ans;
    int size = 1 << n;
    ans.push_back(0);

    for(int i = 1; i < size; i++){
      int tmp = (i >> 1) ^ i;
      ans.push_back(tmp);
    }
    return ans;
  }
};
