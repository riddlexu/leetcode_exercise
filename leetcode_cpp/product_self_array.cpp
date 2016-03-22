//https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans;
    if (nums.size() == 0){
      return ans;
              
    } else if (nums.size() == 1){
      ans.push_back(1);
      return ans;
              
    }

    int x = 1;
    for (int i = 0; i < nums.size(); i++) {
      x = x * nums[i];
      ans.push_back(x);
              
    }
    x = 1;
    for (int i = nums.size() - 1; i >= 0; i--){
      x = x * nums[i];
      nums[i] = x;
              
    }
    nums.push_back(1);

    for (int i = ans.size() - 1; i >= 1; i --) {
      ans[i] = nums[i + 1] * ans[i - 1];
              
    }
    ans[0] = nums[1];
    return ans;     
  }
};
