//https://leetcode.com/problems/power-of-two/

class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }
    if (n < 3) {
      return true;
    }
    while(n % 2 == 0) {
      n = n /2;
    }
    if (n > 1) {
      return false;
    }
    return true;
  }
};
