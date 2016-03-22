//https://oj.leetcode.com/problems/search-a-2d-matrix/

class Solution {
 public:
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int top = 0;
    int bottom = matrix.size();
    if (bottom == 0){
      return false;
    }
    int mid;
    int length = matrix[0].size();
    while(bottom > top + 1){
      mid = (top + bottom) / 2;
      if (matrix[mid][0] > target){
        bottom = mid;
      }
      else if (matrix[mid][length-1] < target){
        top = mid;
      }
      else {
        return binarySearch(matrix[mid],target);
      }
    }
    
    if (bottom == top + 1){
      return binarySearch(matrix[top],target);
    }
    return false;
  }
  bool binarySearch(vector<int> &array, int target){
    if (array.size() == 0){
      return false;
    }

    int left = 0;
    int right = array.size();
    int mid;
    while(left + 1 < right){
      mid = (left + right)/2;
      if (array[mid] == target){
        return true;
      }
      else if (array[mid] > target){
        right = mid;
      }
      else {
        left = mid + 1;
      }
    }
    if (left + 1 == right){
      return array[left] == target ;
    }
    else {
      return false;
    }
  }
};
