//https://oj.leetcode.com/problems/length-of-last-word/

class Solution {
 public:
  int lengthOfLastWord(const char *s) {
    size_t len = strlen(s);
    if (len == 0){
      return 0;
    }
    int loc = len - 1;
    while((loc >= 0) && (s[loc] == ' ')){
      loc--;
    }
    int end = loc;
    if (loc == -1){
      return 0;
    }
    
    while((loc >= 0) && (s[loc] != ' ')){
      loc--;
    }
    if (loc == -1){
      return end + 1;
    }
    else {
      return end -loc;
    }
  }
};
