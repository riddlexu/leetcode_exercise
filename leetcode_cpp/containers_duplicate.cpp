//https://leetcode.com/problems/contains-duplicate/

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    set<int> mymap;
    for(int i = 0; i < nums.size(); i++){
      if(mymap.count(nums[i]) != 0){
        return true;
      }
      mymap.insert(nums[i]);
    }
    return false;
  }
};
