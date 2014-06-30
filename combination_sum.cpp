//https://oj.leetcode.com/problems/combination-sum/

class Solution {
 public:
  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    return sort_combinationSum(candidates,target);
  }
  vector<vector<int> > sort_combinationSum(vector<int> &candidates, int target) {
    vector<vector<int> > ans;
    int now_sum = 0;
    if (candidates.size() == 0){
      return ans;
    }
    
    int now_element = candidates.back();
    candidates.pop_back();
    int element_size = 0;
    while(target > 0){
      vector<vector<int> > res = sort_combinationSum(candidates,target);
      
      for (int i = 0; i < res.size(); ++i){
        ans.push_back(res[i]);
        for (int j = 0; j < element_size; ++j)
        {
          ans[ans.size()-1].push_back(now_element);
        }
      }
      target = target - now_element;
      element_size++;
      if (target == 0){
        vector<int> temp;
        ans.push_back(temp);
        for (int j = 0; j < element_size; ++j)
        {
          ans[ans.size()-1].push_back(now_element);
        }        
      }
    }

    candidates.push_back(now_element);
    return ans;
  }
};
