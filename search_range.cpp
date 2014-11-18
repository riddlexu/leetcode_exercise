//https://oj.leetcode.com/problems/search-for-a-range/

class Solution {
 public:
  vector<int> searchRange(int A[], int n, int target) {
    int left = 0;
    int right = n;
    int middle = -1;
    vector<int> ans;
    while(left < right){
      int mid = (left + right) / 2;
      if(A[mid] < target){
        left = mid + 1;
      }
      else if(A[mid] > target){
        right = mid;
      }
      else{
        middle = mid;
        break;
      }
    }
    if(middle < 0){
      ans.push_back(-1);
      ans.push_back(-1);
      return ans;
    }
    
    int rend = middle;
    while(left < rend){
      int mid = (left + rend) / 2;
      if(A[mid] < target){
        left = mid + 1;
      }
      else{
        rend = mid;
      }
    }
    if(A[left] == target){
      ans.push_back(left);
    }
    else {
      ans.push_back(left+1);
    }
    
    int lend = middle;
    while(lend < right){
      int mid = (lend + right) / 2;
      if(A[mid] > target){
        right = mid;
      }
      else{
        lend = mid + 1;
      }
    }

    ans.push_back(right-1);
      
    return ans;
  }
};
