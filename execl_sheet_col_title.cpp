//https://oj.leetcode.com/problems/excel-sheet-column-title/

class Solution {
 public:
  string convertToTitle(int n) {
    long long x = n;
    long long flag = 26;
    string ans = "";
    int width = 1;
    while(x > flag){
      x = x - flag;
      width++;
      flag = flag * 26;
    }
    x = x - 1;
    for(int i = 0; i < width; i++){
      flag = flag / 26;
      ans.push_back(x/flag + 'A');
      x = x % flag;
    }
    return ans;
  }
};
