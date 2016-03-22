//https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
  string addChar(string s, char c){
    s.push_back(c);
    return s;
  }
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.size() == 0){
      ans.push_back("");
      return ans;
    }

    vector<string> after = letterCombinations(digits.substr(0,digits.size()-1));
    for(int i = 0; i < after.size(); i++){
      char c = (digits[digits.size()-1] - '2')*3+'a';
      if (digits[digits.size() - 1] < '7'){
        ans.push_back(addChar(after[i],c));
        ans.push_back(addChar(after[i],c+1));
        ans.push_back(addChar(after[i],c+2));
      }
      else {
        ans.push_back(addChar(after[i],c+1));
        ans.push_back(addChar(after[i],c+2));
        ans.push_back(addChar(after[i],c+3));

      }
      if (digits[digits.size()-1] == '7'){
        ans.push_back(addChar(after[i],'p'));
      }
      
      if (digits[digits.size()-1] == '9'){
        ans.push_back(addChar(after[i],'z'));
      }
    }
    return ans;
  }
};


