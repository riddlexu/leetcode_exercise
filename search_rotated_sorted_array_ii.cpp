//https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
 public:
  bool search(int A[], int n, int target) {
    int left = 0;
    int right = n-1;
    while(left < right){
      int mid = (left + right) / 2;
      if(A[mid] == target){
        return true;
      }
      else if(A[mid] > target){
        if(A[left] < target){
          right = mid--;
        }
        else if(A[left] == target){
          return true;
        }
        else {
          return true;
        }
      }
      else{
        if(A[
      }
    }
    if(target == A[left]){
      return true;
    }
    return false;
  }
};
