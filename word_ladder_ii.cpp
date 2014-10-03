class Solution {
 public:
  vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
    vector<vector<string>> ans;
    if(start == end){
      vector<string> sol;
      sol.push_back(start);
      ans.push_back(sol);
      return ans;
    }
    vector<vector<string> > parent;
    vector<vector<string> > son;
    vector<string> now;
    now.push_back(start);
    parent.push_back(now);
    bool flag = false;
    while(!dict.empty()){
      while(!parent.empty()){
        now = parent.back();
        string base = now.back();
        for (int i = 0; i < base.size(); ++i){
          for (char j = 'a'; j <= 'z'; ++j){
            if(base[i] != j){
              string tmp = base;
              tmp[i] = j;
              if(tmp == end){
                  flag = true;
                  son.push_back(now);
                  son.back().push_back(tmp);
              }
              if(flag){
                break;
              }
              if(dict.count(tmp) > 0){
                son.push_back(now);
                son.back().push_back(tmp);
              }
            }
          }
        }
        parent.pop_back();
      }
      if(son.empty()){
        return ans;
      }
      if(flag){
        for(int i = 0; i < son.size(); ++i){
          if(son[i].back() == end){
            ans.push_back(son[i]);
          }
        }
        return ans;
      }
      else{
        for(int i = 0; i < son.size(); ++i){
          dict.erase(son[i].back());
        }
      }
      swap(parent,son);
    }
    return ans;
  }
};
