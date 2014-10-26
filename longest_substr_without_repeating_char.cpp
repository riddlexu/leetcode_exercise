//https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int start = 0;
    if(s.size() <= 1){
      return s.size();
    }
    int ans = 1;
    unordered_map<char, int> loc;
    for(int i = 0; i < s.size(); i++){
      if(loc.count(s[i]) != 0){
        start = max(start,loc[s[i]] + 1);
      }
      loc[s[i]] = i;
      ans = max(ans,i-start+1);
    }
    return ans;
  }
};
