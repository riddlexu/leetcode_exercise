//https://oj.leetcode.com/problems/valid-palindrome/

class Solution {
 private:
  bool isLetter(char x){
    return ((x >= 'a') && (x <= 'z')) || ((x >= 'A') && (x <= 'Z'));
  }
 public:
  bool isPalindrome(string s) {
    if (s.size() == 0){
      return true;
    }
    int left = 0;
    int right = s.size() - 1;
    while(left < right){
      while((left < s.size()) && !isalpha(s[left]) && !isalnum(s[left])){
        left++;
      }
      while((right >= 0) && !isalpha(s[right]) && !isalnum(s[right])){
        right--;
      }
      if ((left >= right) || (left >= s.size()) || (right < 0)){
        break;
      }
      if (s[left] != s[right]){
        if (isalpha(s[left]) && isalpha(s[right]) && (abs(s[left] - s[right]) == 32)){
        }
        else{
          return false;
        }
      }
      left++;
      right--;
    }
    return true;
  }
};
