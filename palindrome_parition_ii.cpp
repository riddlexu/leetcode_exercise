//https://oj.leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
 public:
  int minCut(string s) {
    int length = s.size();
    int** matrix = (int**)malloc(sizeof(int*)*length);
    for(int i = 0; i < length; i++){
      matrix[i] = (int*)malloc(sizeof(int)*length);
    }
    int* mincut = (int*)malloc(sizeof(int)*(length+1));
    for(int i = 0; i < length+1; i++){
      mincut[i] = length - i - 1;
    }
        
    for(int i = length - 1; i >= 0; i--){
      for(int j = i; j < length; j++){
        if (((j - i < 2) && (s[i] == s[j])) || ((matrix[i+1][j-1] && s[i] == s[j]))){
          matrix[i][j] = true;
          mincut[i] = min(mincut[i],mincut[j+1] + 1);
        }
        else{
          matrix[i][j] = false;
        }
      }
    }
    return mincut[0];
  }
};
