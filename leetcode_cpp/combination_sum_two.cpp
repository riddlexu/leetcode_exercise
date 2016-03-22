//https://oj.leetcode.com/problems/combination-sum-ii/

class Solution {
 public:
  vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    return sort_combinationSum(num,target);
  }
  vector<vector<int> > sort_combinationSum(vector<int> &num, int target) {
    vector<vector<int> > ans;
    if ((num.size() == 0) || (target == 0)){
      return ans;
    }

    int now_element = num.back();
    num.pop_back();
    int element_size = 1;
    while(num.back() == now_element){
      num.pop_back();
      element_size++;
    }
    for (int i = 0; i <= element_size; ++i){
      vector<vector<int> > res = sort_combinationSum(num,target);
      for (int j = 0; j < res.size(); ++j){
        for (int k = 0; k < i; ++k){
          res[j].push_back(now_element);
        }
        ans.push_back(res[j]);
      }
      if (target == 0){
        vector<int> temp;
        for (int j = 0; j < i; ++j){
          temp.push_back(now_element);
        }
        ans.push_back(temp);
      }
      if (target < 0){
        break;
      }
      target = target - now_element;
    }
    for (int i = 0; i < element_size; ++i){
      num.push_back(now_element);  
    }
    return ans;
  }
};
