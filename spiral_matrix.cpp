#include<iostream>
#include<vector>
using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
        
  }
};

int main()
{
  int n;
  cin >> n;
  vector<vector<int> > matrix;
  for (int i = 0; i < n; ++i){
    vector<int> tmp;
    matrix.push_back(tmp);
    for (int j = 0; j < n; ++j){
      int temp;
      cin >> temp;
      matrix[i].push_back(temp);
    }
  }

  vector<int> ans;
  Solution solution;
  ans = solution.spiralOrder(matrix);
  for (int i = 0; i < n*n; ++i){
    cout << ans << " ";
  }
  cout << endl;
  return 0;
}
