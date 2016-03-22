#include<string>
#include<iostream>
using namespace std;

class ReverseSubstring {
 public:
  void reverseWords(string &s) {
    size_t start_pos, end_pos;
    int left, right;
    char tmp;
    start_pos = 0;
    end_pos = s.find(" ", start_pos);    
    while (end_pos != string::npos){
      left = start_pos;
      right = end_pos - 1;
      while(left < right){
        tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
      }
      start_pos = end_pos + 1;
      while(s[start_pos] == ' '){
        start_pos++;
      }
      if (start_pos - end_pos > 1){
        s.erase(end_pos + 1,start_pos - end_pos - 1);
        start_pos = end_pos + 1;
      }
      end_pos = s.find(" ", start_pos);
    }
    left = start_pos;
    right = s.size() - 1;
    while(left < right){
      tmp = s[left];
      s[left] = s[right];
      s[right] = tmp;
      left++;
      right--;
    }      
  }
};

class Solution{
 public:
  void reverseWords(string &s) {
    normalize(s);
    ReverseSubstring rev;
    char tmp;
    rev.reverseWords(s);
 
    int left = 0;
    int right = s.size() - 1;
    while (left < right){
      tmp = s[left];
      s[left] = s[right];
      s[right] = tmp;
      left++;
      right--;
    }
  }
 private:
  void normalize(string &s){
    int before = 0;
    while(s[before] == ' '){
      before++;
    }
    if (before != 0){
      s.erase(0,before);
    }
    int end = s.size() - 1;
    while((end > 0) && (s[end] == ' ')){
      end--;
    }
    s.resize(end + 1);
  }
};

class Solution {
public:
    void reverseWords(string &s) {
        string ans = "";
        int right = s.size();
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == ' '){
                right = i;
            }
            else if((i == 0) || (s[i-1] == ' ')){
                if(ans.size() != 0){
                    ans.push_back(' ');
                }
                ans.append(s.substr(i,right-i));
            }
        }
        s = ans;
    }
};

int main()
{
  Solution solution;
  string s;
  getline(cin,s);
  solution.reverseWords(s);
  cout << s << "end" << endl;
  return 0;
}
