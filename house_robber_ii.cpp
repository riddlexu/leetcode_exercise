//https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    } else if (nums.size() == 1){
      return nums[0];
    }
    return max(robRange(nums,0, nums.size() - 1), robRange(nums,1,nums.size()));
  }
  int robRange(vector<int>& nums, int start, int end) {
    int sumPre = 0;
    int sumNow = nums[start];
    int tmp;
    for(int i = start + 1; i < end; i++) {
      tmp = sumNow;
      sumNow = max(sumPre + nums[i], sumNow);
      sumPre = tmp;
    }
    return sumNow;
  }
};
