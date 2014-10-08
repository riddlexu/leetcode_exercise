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
      while(!data[pre].empty()){
        now = data[pre].back();
        string base = now.back();
        bool got_it = false;
        for (int i = 0; i < length; ++i){
          if(got_it){
            break;
          }
          for (char j = 'a'; j <= 'z'; ++j){
            if(base[i] != j){
              string tmp = base;
              tmp[i] = j;
              if(tmp == end){
                if(!flag){
                  data[next].clear();
                }
                else {
                  flag = true;
                }
                got_it = true;
                data[next].push_back(now);
                data[next].back().push_back(tmp);
              }
              if(flag){
                break;
              }
              if(dict.count(tmp) > 0){
                data[next].push_back(now);
                data[next].back().push_back(tmp);
              }
            }
          }
        }
        data[pre].pop_back();
      }
      if(data[next].empty()){
        return ans;
      }
      if(flag){
        return data[next];
      }
      else{
        for(int i = 0; i < data[next].size(); ++i){
          dict.erase(data[next][i].back());
        }
      }
      pre = !pre;
      next = !next;
    }
    return ans;
  }
};
