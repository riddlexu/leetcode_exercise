//https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
 public:
  int findMin(vector<int> &num) {
    if(num.size() == 1){
      return num[0];
    }
    int left = 0;
    int right = num.size() - 1;
    while(left < right){
      int mid = (left + right) / 2;
      if(num[mid] < num[right]){
        right = mid;
      }
      else{
        left = mid + 1;
      }
    }
    return num[left];
  }
};
