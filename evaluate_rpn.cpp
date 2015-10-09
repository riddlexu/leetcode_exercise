#include<vector>
#include<stack>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
      //for special cases
      if (tokens.size() == 0){
        return 0;
      }
      else if (tokens.size() == 1){
        return stoi(tokens[0]);
      }
      
      size_t pos = 2;
      stack<int> mystack;
      mystack.push(stoi(tokens[0]));
      mystack.push(stoi(tokens[1]));
      size_t length = tokens.size();
      int a,b;
      while (pos < length){
        if ((tokens[pos] == "+") || (tokens[pos] == "-") || (tokens[pos] == "*") || (tokens[pos] == "/")){
          b = mystack.top();
          mystack.pop();
          a = mystack.top();
          mystack.pop();
        }
        if (tokens[pos] == "+"){
          mystack.push(a+b);
        }
        else if (tokens[pos] == "-"){
          mystack.push(a-b); 
        }
        else if (tokens[pos] == "*"){
          mystack.push(a*b); 
        }
        else if (tokens[pos] == "/"){
          mystack.push(a/b); 
        }
        else{
          mystack.push(stoi(tokens[pos]));
        }
        pos++;
      }
      return mystack.top();
    }
};

int main()
{
  string s;
  getline(cin,s);
  vector<string> tokens;
  size_t start_pos = 0;
  size_t end_pos = s.find(" ", start_pos);
  while(end_pos != string::npos){
    tokens.push_back(s.substr(start_pos,end_pos-start_pos));
    start_pos = end_pos + 1;
    end_pos = s.find(" ", start_pos);
  }
  tokens.push_back(s.substr(start_pos,end_pos-start_pos));

  Solution solution;
      
  cout << solution.evalRPN(tokens) << endl;
  return 0;
}
