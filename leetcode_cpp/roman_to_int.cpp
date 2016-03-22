//https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
  int romanToInt(string s) {
    if (s.size() == 0) {
      return 0;
    }
    int sum = numMap(s[0]);
    for (int i = 1; i < s.size(); i++){
      int r = numMap(s[i]);
      int l = numMap(s[i-1]);
      sum = sum + r;
      if (r > l) {
	sum = sum - 2 * l;
      }
    }
    return sum;
  }
  int numMap(char c) {
    switch (c){
    case 'M': return 1000;
    case 'D': return 500;
    case 'C': return 100;
    case 'L': return 50;
    case 'X': return 10;
    case 'V': return 5;
    case 'I': return 1;
    }
  }
};
