//https://oj.leetcode.com/problems/maximum-product-subarray/

class Solution {
 public:
  int maxProduct(int A[], int n) {
    if(n == 0){
      return 0;
    }
    int min = A[0];
    int max = A[0];
    int ans = A[0];
    for(int i = 1; i < n; i++){
      int tmpmin = min*A[i];
      int tmpmax = max*A[i];
      min = std::min(std::min(tmpmin,tmpmax),A[i]);
      max = std::max(std::max(tmpmin,tmpmax),A[i]);
      ans = std::max(ans,max);
    }
    return ans;
  }
};
