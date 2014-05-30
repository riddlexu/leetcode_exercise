#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string s = "";
    generate_rec(ans,n,n,s);
    return ans;
  }
  void generate_rec(vector<string> &ans, int left, int right, string s){
    if ((left == 0) && (right == 0)){
      ans.push_back(s);
    }
    if (left > 0){
      generate_rec(ans,left-1,right,s+'(');
    }
    if (left < right){
      generate_rec(ans,left,right-1,s+')');
    }
  }
};

int main()
{
  int n;
  cin >> n;
  Solution solution;
  vector<string> ans = solution.generateParenthesis(n);
  for (unsigned int i = 0; i < ans.size(); i++){
    cout << ans[i] << endl;
  }
}
