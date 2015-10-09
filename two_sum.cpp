//https://oj.leetcode.com/problems/two-sum/

class Solution {
 public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    unordered_set<int> hashset;
    vector<int> ans;
    int rindex = -1;
    for (int i = 0; i < numbers.size(); ++i){
      if (hashset.find(target-numbers[i]) == hashset.end()){
        hashset.insert(numbers[i]); 
      }
      else{
        rindex = i;
        break;
      }
    }
    for (int i = 0; i < rindex; ++i){
      if (target - numbers[i] == numbers[rindex]){
        ans.push_back(i+1);
        ans.push_back(rindex+1);
        return ans;
      }
    }
  }
};
