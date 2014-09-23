class Solution {
 public:
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    vector<vector<string> > ans;
    for (int i = 0; i < s.size(); i++){
      vector<string> sol;
      ans.push_back(sol);
      for(int j = 0; j < i; j++){
        if (ans[j].size() > 0){
          string tmp = s.substr(j+1,i-j);
          if (dict.count(tmp)){
            for(int k = 0; k < ans[j].size(); k++){
              ans[i].push_back(ans[j][k] + " " + tmp);
            }
          }
        }
      }
      string now = s.substr(0,i+1);
      if (dict.count(now)){
        ans[i].push_back(now);
      }
    }
    return ans[s.size()-1];
  }
};
