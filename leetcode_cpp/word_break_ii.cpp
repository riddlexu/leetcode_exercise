class Solution {
  vector<string> res;
  vector<vector<bool> > flag;
  vector<string> state;
 public:
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    if (s.size() == 0){
      return res;
    }
    if (!haveSolution(s,dict)){
      return res;
    }
    int length = s.size();
    for(int i = 0; i < length; i++){
      vector<bool> tmp;
      flag.push_back(tmp);
      for(int j = i; j < length; j++){
        if (dict.find(s.substr(i,j-i+1)) != dict.end()){
          flag[i].push_back(true);
        }
        else{
          flag[i].push_back(false);
        }
      }
    }
    parser(s,0);
    return res;
  }
  void parser(string s, int loc){
    if(loc >= s.size()){
      string sol = state[0];
      for(int i = 1; i < state.size(); i++){
        sol = sol + " " + state[i];
      }
      res.push_back(sol);
      return;
    }
    for (int i = loc; i < s.size(); ++i){
      if(flag[loc][i-loc]){
        state.push_back(s.substr(loc,i-loc+1));
        parser(s,i+1);
        state.pop_back();
      }
    }
  }
  bool haveSolution(string s, unordered_set<string> &dict) {
    if (s.size() == 0){
      return true;
    }
    if (dict.size() == 0){
      return false;
    }
    bool* f = (bool*)malloc(sizeof(bool)*s.size());
    for(int i = 0; i < s.size(); i++){
      f[i] = false;
    }
    for(int i = 0; i < s.size(); i++){
      f[i] = dict.count(s.substr(0,i+1));
      if (f[i]){
        continue;
      }
      for (int j = 0; j < i; ++j){
        if (f[j] && dict.count(s.substr(j+1,i-j))){
          f[i] = true;
          break;
        }
      }
    }
    return f[s.size() - 1];
  }
};


