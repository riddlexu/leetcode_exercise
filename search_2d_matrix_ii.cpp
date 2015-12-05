//https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) {
      return false;
    }
    int n = matrix[0].size();
    if (n == 0) {
      return false;
    }

    int x = 0;
    int y = n - 1;
    while((x >= 0) && (x < m) && (y >= 0) && (y < n)){
      if (matrix[x][y] == target) {
	return true;
      } else if (matrix[x][y] < target) {
	x = x + 1;
      } else {
	y = y - 1;
      }
    }
    return false;
  }
};
