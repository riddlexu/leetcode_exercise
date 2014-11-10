//https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
 public:
  bool search(int A[], int n, int target) {
    int left = 0;
    int right = n-1;
    while(left <= right){
      int mid = (left + right) / 2;
      if(A[mid] == target){
        return true;
      }
      else if(A[mid] > target){
        if(A[left] < A[right]){
          right = mid - 1;
        }
        else if(A[left] == A[right]){
          if(A[left] == target){
            return true;
          }
          else{
            left++;
            right--;
          }
        }
        else {
          if(A[right] >= A[mid]){ // caution!!!
            right = mid - 1;
          }
          else if(A[left] > target){
            left = mid + 1;
          }
          else{
            right = mid - 1;
          }
        }
      }
      else{
        if(A[left] < A[right]){
          left = mid + 1;
        }
        else if(A[left] == A[right]){
          if(A[left] == target){
            return true;
          }
          else {
            left++;
            right--;
          }
        }
        else{
          if(A[left] <= A[mid]){
            left = mid + 1;
          }
          else if(A[left] > target){
            left = mid + 1;
          }
          else{
            right = mid - 1; //caution!!!
          }
        }
      }
    }
    
    return false;
  }
};
