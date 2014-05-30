#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        
    }
};

int main()
{
  int n,temp;
  cin >> n;
  vector<int> num;
  for (int i = 0; i < n; i++){
    cin >> temp;
    num.push_back(temp);
  }
  Solution solution;
  vector<vector<int> > ans = solution.permute(num);
  for (unsigned int i = 0; i < ans.size(); i++){
    for (unsigned int j = 0; j < ans[i].size(); j++){
      cout << ans[i][j];
    }
    cout << endl;
  }
}
