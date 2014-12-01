//https://oj.leetcode.com/problems/count-and-say/

class Solution {
 public:
  string countAndSay(int n) {
    if (n <= 0){
      return "";
    }
    string ans = "1";
    for (int k = 1; k < n; k++){
      char now = ans[0];
      string sol = "";
      int num = 1;
      for (int i = 1; i < ans.size(); i++){
        if(ans[i] != now){
          sol.push_back(('1'+(num-1)));
          sol.push_back(now);
          now = ans[i];
          num = 1;
        }
        else {
          num++;
        }
      }
      sol.push_back(('1'+(num-1)));
      sol.push_back(now);
      ans = sol;
    }
    return ans;
  }
};
