#include<iostream>
#include<string>
#include<stack>
using namespace std;


class Solution {
 public:
  vector<string> generateParenthesis(int n) {
        
  }
};

int main()
{
  int n;
  cin >> n;
  vector<string> ans = Solution.generateParenthesis(n);
  for (int i = 0; i < ans.size(); i++){
    cout << ans[i] << endl;
  }
}
