//https://oj.leetcode.com/problems/longest-palindromic-substring/

class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.size() <= 1){
      return s;
    }
    int len = 1;
    int start = 0;
    for(int i = 0; i < s.size(); i++){
      int begin = i;
      int end = i+1;
      while((end < s.size()) && (s[end-1] == s[end])){
        end++;
      }
      while((begin > 0) && (end < s.size()) && (s[begin-1] == s[end])){
        begin--;
        end++;
      }
      if (end - begin > len){
        len = end - begin;
        start = begin;
      }
    }
    return s.substr(start,len);
  }
};
