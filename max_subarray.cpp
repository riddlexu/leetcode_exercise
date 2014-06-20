//https://oj.leetcode.com/problems/maximum-subarray/

class Solution {
 public:
  int maxSubArray(int A[], int n) {
    int array = 0;
    int max_array = INT_MIN;
    for (int i = 0; i < n; ++i){
      if (array < 0){
        array = 0;
      }
      array += A[i];
      max_array = std::max(array,max_array);
    }
    return max_array;
  }
};
