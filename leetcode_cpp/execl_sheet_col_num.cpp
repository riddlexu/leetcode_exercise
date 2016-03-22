//https://oj.leetcode.com/problems/excel-sheet-column-number/

class Solution {
 public:
  int titleToNumber(string s) {
    int n = s.size();
    int base = 1;
    int ans = 0;
    vector<int> array;
    for(int i = 0; i < n; i++){
      array.push_back(base);
      base = base*26;
    }
    for(int i = 0; i < n; i++){
      ans = ans + array[i];
    }
    for(int i = 0; i < n; i++){
      ans = ans + (s[i] - 'A')*array[n-i-1];
    }
    return ans;
  }
};
