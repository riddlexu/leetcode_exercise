//https://oj.leetcode.com/problems/subsets/

class Solution {
 public:
  vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(), S.end());
    return sorted_subsets(S);
  }
  vector<vector<int> > sorted_subsets(vector<int> &S) {
    vector<vector<int> > ans;
    if (S.size() == 0){
      vector<int> temp;
      ans.push_back(temp);
      return ans;
    }
    int back = S.back();
    S.pop_back();
    vector<vector<int> > without_back = subsets(S);
    ans = without_back;
    for (int i = 0; i < without_back.size(); ++i){
      without_back[i].push_back(back);
      ans.push_back(without_back[i]);
    }
    return ans;
  }
};
