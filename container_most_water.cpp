//https://oj.leetcode.com/problems/container-with-most-water/

class Solution {
 public:
  int maxAreaSlow(vector<int> &height) {
    int ans = 0;
    for (int i = 1; i < height.size(); i++){
      if (height[i] == 0){
        continue;
      }
      int maxj = i - ans / height[i];
      for (int j = 0; j < i && j < maxj; j++){
        int res = std::min(height[i],height[j]) * (i - j);
        if (res > ans){
          ans = res;
        }
      }
    }
    return ans;
  }
  int maxArea(vector<int> &height){
    int ans = 0;
    int left = 0;
    int right = height.size() - 1;
    while(left < right){
      int res = std::min(height[left],height[right]) * (right - left);
      if (res > ans){
        ans = res;
      }
      if (height[left] > height[right]){
        right--;
      }
      else if (height[left] == height[right]){
        left++;
        right--;
      }
      else {
        left++;
      }
    }
    return ans;
  }
};
