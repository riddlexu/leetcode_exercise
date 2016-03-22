//https://oj.leetcode.com/problems/string-to-integer-atoi/

class Solution {
 public:
  int atoi(const char *str) {
    int length = strlen(str);
    int loc = 0;
    if(length == 0){
      return 0;
    }
    int positive = 1;
    bool sym = false;
    long long ans = 0;
    while((loc < length) && (str[loc] == ' ')){
      loc++;
    }

    while(loc < length){
      if((str[loc] > '9') || (str[loc] < '0')){
        if(str[loc] == '-'){
          if(sym){
            return 0;
          }
          else{
            positive = -1;
            sym = true;
            loc++;
            continue;
          }
        }
        else if(str[loc] == '+'){
          if(sym){
            return 0;
          }
          else{
            sym = true;
            loc++;
            continue;
          }
        }
        else{
          break;
        }
        
      }
      ans = ans * 10 + (str[loc] - '0');
      if(ans > INT_MAX){
        if(positive == 1){
          return INT_MAX;
        }
        else{
          return INT_MIN;
        }
      }
      loc++;
    }
    return ans*positive;    
  }
};
