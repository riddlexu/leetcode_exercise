//https://oj.leetcode.com/problems/maximum-subarray/

class Solution {
 public:
  int maxSubArray(int A[], int n) {
    // int array = 0;
    // int max_array = INT_MIN;
    // for (int i = 0; i < n; ++i){
    //   if (array < 0){
    //     array = 0;
    //   }
    //   array += A[i];
    //   max_array = std::max(array,max_array);
    // }
    // return max_array;
    return divide(A, 0,n);
  }

  int divide(int A[], int left, int right){
    if (left == right - 1){
      return A[left];
    }
    if (left == right - 2){
      return std::max(A[left] + A[left+1], std::max(A[left],A[left+1]));
    }
    int middle = (left + right) / 2;
    int lmax = divide(A,left, middle);
    int rmax = divide(A,middle+1,right);

    int mid_max = A[middle];
    int array = A[middle];
    for (int i = middle+1; i < right; ++i){
      array += A[i];
      if (array > mid_max){
        mid_max = array;
      }
    }
    array = mid_max;
    for (int i = middle-1; i >= left; --i){
      array += A[i];
      if (array > mid_max){
        mid_max = array;
      }
    }
    return std::max(mid_max,std::max(lmax,rmax));
  }
};
