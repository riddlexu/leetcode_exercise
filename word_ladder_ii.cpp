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
    vector<vector<string> > data[2];
    vector<string> now;
    now.push_back(start);
    int pre = 0;
    int next = 1;
    data[pre].push_back(now);
    bool flag = false;
    dict.erase(start);
    dict.erase(end);
    int length = start.size();
    
    while(!dict.empty()){
      for(int k = 0; k < data[pre].size(); k++){
        now = data[pre][k];
        string base = now.back();
        for (int i = 0; i < length; ++i){
          if(flag){
            break;
          }
          for (char j = 'a'; j <= 'z'; ++j){
            if(base[i] != j){
              string tmp = base;
              tmp[i] = j;
              if(tmp == end){
                if(!flag){
                  flag = true;
                }
                now.push_back(end);
                ans.push_back(now);
              }
              if(flag){
                break;
              }
              if(dict.count(tmp) > 0){
                now.push_back(tmp);
                data[next].push_back(now);
                now.pop_back();
              }
            }
          }
        }
      }
      if(data[next].empty() || flag){
        return ans;
      }
      else{
        for(int i = 0; i < data[next].size(); ++i){
          dict.erase(data[next][i].back());
        }
      }
      pre = !pre;
      next = !next;
      data[next].clear();
    }
    return ans;
  }
};
