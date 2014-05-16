#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
      return 0;
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
