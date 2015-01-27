//https://oj.leetcode.com/problems/factorial-trailing-zeroes/

class Solution {
 public:
  int trailingZeroes(int n) {
    long long x = 5;
    int ans = 0;
    int iter = 1;
    while(x <= n){
      ans = ans + (n / x);
      x = x * 5;
    }
    return ans;
  }
};
