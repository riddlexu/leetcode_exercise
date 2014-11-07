//https://oj.leetcode.com/problems/set-matrix-zeroes/

class Solution {
 public:
  void setZeroes(vector<vector<int> > &matrix) {
    bool top = false;
    bool left = false;
    int height = matrix.size();
    int width = matrix[0].size();
    if(matrix[0][0] == 0){
      top = true;
      left = true;
    }
    else{
      for(int i = 1; i < height; i++){
        if(matrix[i][0] == 0){
          left = true;
          break;
        }
      }
      for(int i = 1; i < width; i++){
        if(matrix[0][i] == 0){
          top = true;
          break;
        }
      }
    }
        
    for(int i = 1; i < height; i++){
      for(int j = 1; j < width; j++){
        if(matrix[i][j] == 0){
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }
        
    for(int i = 1; i < height; i++){
      if(matrix[i][0] == 0){
        for(int j = 1; j < width; j++){
          matrix[i][j] = 0;
        }
      }
    }
    for(int i = 1; i < width; i++){
      if(matrix[0][i] == 0){
        for(int j = 1; j < height; j++){
          matrix[j][i] = 0;
        }
      }
    }
        
    if(top){
      for(int i = 0; i < width; i++){
        matrix[0][i] = 0;
      }
    }
    if(left){
      for(int i = 0; i < height; i++){
        matrix[i][0] = 0;
      }
    }
  }
};
