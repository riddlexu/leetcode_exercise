//https://leetcode.com/problems/happy-number/

class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> myset = {n};
    while(true) {
      n = getNumber(n);
      if (n == 1) {
	return true;
      }
      if (myset.count(n) > 0) {
	return false;
      }
      myset.insert(n);
    }
  }
  int getNumber(int n) {
    if (n <= 1) {
      return n;
    }
    int sum = 0;
    int digit = 0;
    while (n != 0) {
      digit = n % 10;
      sum += digit * digit;
      n = n / 10;
    }
    return sum;
  }
};
