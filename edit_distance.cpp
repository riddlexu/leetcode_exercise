//https://oj.leetcode.com/problems/edit-distance/

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int x = word1.size();
    int y = word2.size();
    if(y == 0){
      return x;
    }
    if(x == 0){
      return y;
    }
        
    int** a = (int**)malloc(sizeof(int*)*(x+1));
    for(int i = 0; i < x+1; i++){
      a[i] = (int*)malloc(sizeof(int)*(y+1));
    }
        
    for(int i = 0; i < x+1; i++){
      a[i][0] = i;
    }
    for(int i = 0; i < y+1; i++){
      a[0][i] = i;
    }
        
    for(int i = 1; i < x+1; i++){
      for(int j = 1; j < y+1; j++){
        if(word1[i-1] == word2[j-1]){
          a[i][j] = a[i-1][j-1];
        }
        else{
          a[i][j] = std::min(std::min(a[i-1][j],a[i][j-1]),a[i-1][j-1]) + 1;
        }
      }
    }

    int ans = a[x][y];

    for(int i = 0; i < x + 1; i++){
      free(a[i]);
    }
    free(a);
    
    return ans;
  }
};
