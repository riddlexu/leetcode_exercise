//https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
 public:
  int findMin(vector<int> &num) {
    int n = num.size();
    if(n == 1){
      return num[0];
    } 
    int left = 0;
    int right = n - 1;
    while(left < right){
      int mid = (left + right) / 2;
      if(num[left] < num[right]){
        return num[left];
      }
      else if(num[left] == num[right]){
        right = right - 1;
      }
      else{
        if(num[right] < num[mid]){
          left = mid + 1;
        }
        else{
          right = mid;
        }
      }
    }
    return num[left];
  }
};
