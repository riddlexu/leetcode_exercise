//https://oj.leetcode.com/problems/triangle/

class Solution {
 public:
  int minimumTotal(vector<vector<int> > &triangle) {
    int height = triangle.size();
    if (height == 0){
      return 0;
    }
    else if (height == 1){
      return triangle[0][0];
    }
    for (int i = 1; i < height; ++i){
      triangle[i][0] += triangle[i-1][0];
      for (int j = 1; j < triangle[i].size() - 1; ++j){
        triangle[i][j] += std::min(triangle[i-1][j-1],triangle[i-1][j]);
      }
      triangle[i][triangle[i].size() - 1] += triangle[i-1][triangle[i-1].size() - 1];
    }

    int min = triangle[height-1][0];
    for (int i = 1; i < height; ++i)
    {
      if (triangle[height-1][i] < min){
        min = triangle[height-1][i];
      }
    }
    return min;
  }
};
