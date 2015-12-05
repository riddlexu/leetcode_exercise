//https://leetcode.com/problems/house-robber/

class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.empty()){
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }
    int sumPre = 0;
    int sumNow = nums[0];
    int tmp;
    for (int i = 1; i < nums.size(); i++) {
      tmp = sumNow;
      sumNow = max(sumPre + nums[i], sumNow);
      sumPre = tmp;
    }
    return sumNow;
  }
};
