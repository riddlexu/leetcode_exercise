//https://oj.leetcode.com/problems/palindrome-number/

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0){
      return false;
    }
    if (x < 10){
      return true;
    }
    int tmp = x;
    int length = 1;
    int pow_10 = 1;
    while(tmp >= 10){
      tmp = tmp / 10;
      ++length;
      pow_10 = pow_10*10;
    }
    tmp = x;
    int head,end;
    for (int i = 0; i < length/2; ++i){
      end = tmp % 10;
      head = tmp / pow_10;
      if (head != end){
        return false;
      }
      tmp = tmp % pow_10;
      tmp = tmp / 10;
      pow_10 = pow_10 / 100;
    }
    return true;
  }
};
