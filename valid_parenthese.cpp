#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    if (s.size() % 2 != 0){
      return false;
    }
    if (s.size() == 0){
      return true;
    }
    stack<char> mystack;
    size_t loc = 1;
    mystack.push(s[0]);
    char top;
    do{
      if (mystack.size() ==0){
        mystack.push(s[loc]);
        loc++;      
      }
      top = mystack.top();
      switch(s[loc]){
        case ')':
          if (top == '('){
            mystack.pop();
          }
          else {
            return false;
          }
          break;
        case ']':
          if (top == '['){
            mystack.pop();
          }
          else {
            return false;
          }
          break;
        case '}':
          if (top == '{'){
            mystack.pop();
          }
          else {
            return false;
          }
          break;
        case '(':
        case '{':
        case '[':
          mystack.push(s[loc]);
          break;
        default:
          cout << "there is an error" << endl;
      }
      loc++;
    }
    while(s.size() > loc);      
   
    if (mystack.size() > 0){
      return false;
    }
    return true;
  }
};

int main()
{
  string s;
  cin >> s;
  Solution solution;
  cout << solution.isValid(s) << endl;
}
