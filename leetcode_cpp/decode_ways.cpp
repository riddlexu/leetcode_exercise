//https://oj.leetcode.com/problems/decode-ways/

class Solution {
 public:
  int numDecodings(string s) {
    int len = s.size();
    if((len < 1) || (s[0] == '0')){
      return 0;
    }

    int* sol = (int*)malloc(sizeof(int)*len);
    
    sol[0] = 1;
    for(int i = 1; i < len; i++){
      sol[i] = 0;
      if(s[i] > '0'){
        sol[i] = sol[i-1];
      }
      if((s[i-1] == '1') || ((s[i-1] == '2') && (s[i] <= '6'))){
        if(i == 1){
          sol[i]++;
        }
        else{
          sol[i] += sol[i-2];
        }
      }
    }
    return sol[len-1];
  }
};
