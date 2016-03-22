//https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    if (nums.size() <= 2) {
      return nums[0];
    }
    int left = 1;
    int right = nums.size() - 1;
    int mid;
    while(left < right) {
      mid = (left + right) / 2;
      int smaller = 0;
      int equal = 0;
      for(int i = 0; i < nums.size(); i++){
	if (nums[i] == mid) {
	  equal++;
	} else if (nums[i] < mid) {
	  smaller++;
	}
      }
      if (equal > 1) {
	return mid;
      }
      if (smaller < mid) {
	left = mid + 1;
      } else {
	right = mid - 1;
      }
    }
    return (left + right) / 2;
  }
};
