//https://leetcode.com/problems/ugly-number/

class Solution {
public:
  bool isUgly(int num) {
    int x = num;
    if (x <= 0) {
      return false;
    }
    if (x == 1) {
      return true;
    }
    while(x % 5 == 0) {
      x = x / 5;
    }
    while(x % 3 == 0) {
      x = x / 3;
    }
    while(x % 2 == 0) {
      x = x / 2;
    }
    if (x > 1) {
      return false;
    }
    return true;
  }
};
