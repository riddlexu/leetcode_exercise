//https://oj.leetcode.com/problems/subsets-ii/

class Solution {
 public:
  vector<vector<int> > subsetsWithDup(vector<int> &S) {
    sort(S.begin(),S.end());
    return sorted_subsetsWithDup(S);
  }
  vector<vector<int> > sorted_subsetsWithDup(vector<int> &S) {
    vector<vector<int> > ans;
    if (S.size() == 0){
      vector<int> temp;
      ans.push_back(temp);
      return ans;
    }
    
    int back = S.back();
    int dup_len = 0;
    do{
      S.pop_back();
      dup_len++;
    }
    while((S.size() > 0) && (S.back() == back));
    vector<vector<int> > without_back = subsetsWithDup(S);
    ans = without_back;
    for (int l = 0; l < dup_len; ++l){
      for (int i = 0; i < without_back.size(); ++i){
        without_back[i].push_back(back);
        ans.push_back(without_back[i]);
      }
    }

    return ans;
  }
};
