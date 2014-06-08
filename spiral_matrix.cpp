//https://oj.leetcode.com/problems/spiral-matrix/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> ans;
    int m = matrix.size();
    if (m == 0){
      return ans;
    }
    int n = matrix[0].size();
    if (n == 0){
      return ans;
    }

    if (n == 1){
      for (int i = 0; i < m; ++i){
        ans.push_back(matrix[i][0]);
      }
      return ans;
    }
    else if (m == 1){
      for (int i = 0; i < n; ++i){
        ans.push_back(matrix[0][i]);
      }
      return ans;
    }

    int left = 0;
    int right = n;
    int top = 0;
    int bottom = m;

    while((left >= right) && (top >= bottom)){
      
    }
    return ans;
  }
};

int main()
{
  int m,n;
  cin >> m >> n;
  vector<vector<int> > matrix;
  for (int i = 0; i < m; ++i){
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
  cout << "size=" << ans.size() << endl;
  for (int i = 0; i < m*n; ++i){
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
