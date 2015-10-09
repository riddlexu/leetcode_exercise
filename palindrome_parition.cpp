//https://oj.leetcode.com/problems/palindrome-partitioning/

class Solution {
 public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    if(s.size() == 0){
      return ans;
    }
    else if(s.size() == 1){
      vector<string> sol;
      sol.push_back(s);
      ans.push_back(sol);
      return ans;
    }
        
    for(int i = 0; i < s.size() - 1; i++){
      string now = s.substr(0,i+1);
      if(isPalindrome(now)){
        string after = s.substr(i+1,s.size() - i - 1);
        vector<vector<string>> next = partition(after);
        if(next.size() > 0){
          for(int j = 0; j < next.size(); j++){
            next[j].insert(next[j].begin(),now);
            ans.push_back(next[j]);
          }
        }
      }
    }
    if(isPalindrome(s)){
      vector<string> sol;
      sol.push_back(s);
      ans.push_back(sol);
    }
    return ans;
  }
  bool isPalindrome(string s){
    if(s.size() <= 1){
      return true;
    }
    int start = 0;
    int end = s.size() - 1;
    while(start < end){
      if(s[start] != s[end]){
        return false;
      }
      start++;
      end--;
    }
    return true;
  }
};
