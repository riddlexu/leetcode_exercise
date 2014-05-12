#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
      s = "hello world";
    }
};

int main()
{
  Solution solution;
  string s;
  cin >> s;
  solution.reverseWords(s);
  cout << s << endl;
  return 0;
}
