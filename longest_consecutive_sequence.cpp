//https://oj.leetcode.com/problems/longest-consecutive-sequence/

class Solution {
 public:
  int longestConsecutive(vector<int> &num) {
    if (num.size() < 2){
      return num.size();
    }
    unordered_set<int> hashset;
    for (int i = 0; i < num.size(); ++i){
      hashset.insert(num[i]);
    }
    int maxlen = 0;
    for (int i = 0; i < num.size(); ++i){
      hashset.erase(num[i]);

      int now = num[i]+1;
      int right = 1;
      while(hashset.find(now) != hashset.end()){
        right++;
        hashset.erase(now);
        now++;
      }
      
      now = num[i] - 1;
      int left = 0;
      while(hashset.find(now) != hashset.end()){
        left++;
        hashset.erase(now);
        now--;
      }
      if (right + left > maxlen){
        maxlen = right + left;
      }
    }
    return maxlen;
  }
};
