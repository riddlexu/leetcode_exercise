#include<iostream>
#include<vector>
using namespace std;

class Solution {
 public:
  vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > ans;
    vector<int> start;
    permute_rec(ans,start,num);
    return ans;
  }
  void permute_rec(vector<vector<int> > &ans, vector<int> start, vector<int> left){
    if (left.size() == 0){
      ans.push_back(start);
      return;
    }
    if (left.size() == 1){
      start.push_back(left[0]);
      ans.push_back(start);
      return;
    }
    for (unsigned int i = 0; i < left.size(); i++){
      vector<int> new_start = start;
      vector<int> new_left = left;
      new_start.push_back(left[i]);
      new_left.erase(new_left.begin()+i);
      permute_rec(ans,new_start,new_left);
    }
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
