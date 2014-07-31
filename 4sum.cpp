//https://oj.leetcode.com/problems/4sum/

class Solution {
 public:
  vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int> > ans;
    if (num.size() < 4){
      return ans;
    }
    sort(num.begin(),num.end());
    for (int i = 0; i < num.size() - 3; i++){
      if (i != 0){
        if (num[i] == num[i - 1]){
          continue;
        }
      }
      for (int j = i + 1; j < num.size() - 2; j++){
        if (j != i + 1){
          if (num[j] == num[j - 1]){
            continue;
          }
        }
        int left = j + 1;
        int right = num.size() - 1;
        while(left < right){
          int sum = num[i] + num[j] + num[left] + num[right];
          if (sum == target){
            vector<int> temp;
            temp.push_back(num[i]);
            temp.push_back(num[j]);
            temp.push_back(num[left]);
            temp.push_back(num[right]);
            ans.push_back(temp);
            do{
              left++;
            }
            while((left < right) && (num[left] == num[left - 1]));
            do{
              right--;
            }
            while((left < right) && (num[right] == num[right + 1]));
          }
          else if (sum < target){
            do{
              left++;
            }
            while((left < right) && (num[left] == num[left - 1]));
          }
          else {
            do{
              right--;
            }
            while((left < right) && (num[right] == num[right + 1]));
          }
        }
      }
    }
    return ans;
  }
};
