//https://oj.leetcode.com/problems/restore-ip-addresses/

class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    return search(s,4);
  }
  vector<string> search(string s, int level){
    vector<string> ans;
    if((s.size() > level*3) || (s.size() < level)){
      return ans;
    }
    for(int i = 1; i <= min(3,(int)s.size()-level+1); i++){
      vector<string> sol;
      string new_str;
      new_str = s.substr(0,i);
      if(stoi(new_str) <= 255){
        if(s.size() == i){
          ans.push_back(new_str);
          break;
        }
        sol = search(s.substr(i),level-1);
        for(int j = 0; j < sol.size(); j++){
          string tmp = new_str + '.' + sol[j];
          ans.push_back(tmp);
        }
      }
      if(stoi(new_str) == 0){
        break;
      }
    }
    return ans;
  }
};
