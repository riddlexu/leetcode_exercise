//https://oj.leetcode.com/problems/implement-strstr/

class Solution {
 public:
  int strStr(char *haystack, char *needle) {
    int m = strlen(needle);
    int n = strlen(haystack);
    if (m > n){
      return -1;
    }
    if(m == 0){
      return 0;
    }
    for(int i = 0; i <= n - m; i++){
      bool flag = true;
      for(int j = 0; j < m; j++){
        if(haystack[i+j] != needle[j]){
          flag = false;
          break;
        }
      }
      if(flag){
        return i;
      }
    }
    return -1;
  }
};
