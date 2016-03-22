//https://leetcode.com/problems/single-number-iii/

class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    int val = 0;
    for(int i = 0; i < nums.size(); i++){
      val = val ^ nums[i];
    }
    int tmp = val & (-val);
    int a = 0;
    int b = 0;
    for(int i = 0; i < nums.size(); i++){
      if (nums[i] & tmp) {
	a = a ^ nums[i];
      } else {
	b = b ^ nums[i];
      }
    }
    vector<int> sol;
    sol.push_back(a);
    sol.push_back(b);
    return sol;
  }
};
