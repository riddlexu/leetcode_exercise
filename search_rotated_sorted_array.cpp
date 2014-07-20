//https://oj.leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
 public:
  int search(int A[], int n, int target) {
    if (n == 0){
      return -1;
    }  
    if (n == 1){
      if (A[0] == target){
        return 0;
      }
      return -1;
    }
    int start = 0;
    int end = n;
    int mid;
    do{
      mid = (start + end) / 2;
      if (A[mid] > target){
        if ((A[start] > A[end - 1]) && (A[end-1] >= target) && (A[mid] > A[end-1])){
          start = mid;
        }
        else if (A[start] == target){
          return start;
        }
        else {
          end = mid;
        }
      }
      else if (A[mid] == target){
        return mid;
      }
      else {
        if ((A[start] < target) && (A[end-1] < A[start]) && (A[mid] < A[start])){
          end = mid;
        }
        else if (A[start] == target){
          return start;
        }
        else{
          start = mid;
        }
      }
    }
    while(start < end - 1);
    return -1;
  }
};
