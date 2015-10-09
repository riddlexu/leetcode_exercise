//https://oj.leetcode.com/problems/majority-element/

class Solution {
 public:
  int majorityElement(vector<int> &num) {
    int maj;
    int count = 0;
    for (int i = 0; i < num.size(); i++){
      if (count == 0){
        maj = num[i];
        count = 1;
      }
      else if (num[i] == maj){
        count++;
      }
      else {
        count--;
      }
    }
    return maj;
  }
};
