//https://oj.leetcode.com/problems/find-peak-element/

class Solution {
 public:
  int findPeakElement(const vector<int> &num) {
    if (num.size() == 1){
      return 0;
    }
    int start = 0;
    int end = num.size() - 1;
    while(start < end){
      if (end - start == 1){
        if (num[start] > num[end]){
          return start;
        }
        else {
          return end;
        }
      }
      int mid = (start + end)/ 2;
      if(num[mid] > num[mid-1]){
        start = mid;
      }
      else {
        end = mid;
      }
    }
    return start;
  }
};
