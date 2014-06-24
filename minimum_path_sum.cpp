//https://oj.leetcode.com/problems/minimum-path-sum/

class Solution {
 public:
  int minPathSum(vector<vector<int> > &grid) {
    int height = grid.size();
    if (height == 0){
      return 0;
    }
    int length = grid[0].size();
    if (length == 0){
      return 0;
    }
    for (int i = 1; i < height; ++i){
      grid[i][0] += grid[i-1][0];
    }
    for (int i = 1; i < length; ++i){
      grid[0][i] += grid[0][i-1];
    }
    for (int i = 1; i < height; ++i){
      for (int j = 1; j < length; ++j){
        grid[i][j] += std::min(grid[i-1][j],grid[i][j-1]);
      }
    }
    return grid[height-1][length-1];
  }
};
