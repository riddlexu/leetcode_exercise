//https://oj.leetcode.com/problems/add-binary/

class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    bool a_long;
    int small_size;
    int a_size = a.size();
    int b_size = b.size();
    
    if (a_size >= b_size){
      a_long = true;
      small_size = b_size;
    }
    else{
      a_long = false;
      small_size = a_size;
    }

    char plus = '0';
    for (int i = 1; i <= small_size; ++i){
      if (a[a_size-i] == b[b_size-i]){
        ans.insert(ans.begin(),plus);
        plus = a[a_size-i];
      }
      else{
        if (plus == '0'){
          ans.insert(ans.begin(),'1');
        }
        else{
          ans.insert(ans.begin(),'0');
        }
      }
    }

    if (a_long){
      for (int i = small_size + 1; i <= a_size; ++i){
        if (a[a_size-i] == '0'){
          ans.insert(ans.begin(),plus);
          plus = '0';
        }
        else {
          if (plus == '0'){
            ans.insert(ans.begin(),'1');
          }
          else{
            ans.insert(ans.begin(),'0');
          }
        }
      }
    }
    else{
      for (int i = small_size + 1; i <= b_size; ++i){
        if (b[b_size-i] == '0'){
          ans.insert(ans.begin(),plus);
          plus = '0';
        }
        else {
          if (plus == '0'){
            ans.insert(ans.begin(),'1');
          }
          else{
            ans.insert(ans.begin(),'0');
          }
        }
      }
    }
    if (plus == '1'){
      ans.insert(ans.begin(),'1');
    }
    return ans;
  }
};
