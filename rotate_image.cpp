#include<iostream>
#include<vector>
using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int> > &matrix) {
    int size = matrix.size();
    int temp;
    for (int i = 0; i < size / 2; ++i){
      for (int j = i; j < size - i - 1; ++j){
        temp = matrix[i][j];
        matrix[i][j] = matrix[size-j-1][i];
        matrix[size-j-1][i] = matrix[size-i-1][size-j-1];
        matrix[size-i-1][size-j-1] = matrix[j][size-i-1];
        matrix[j][size-i-1] = temp;
      }
    }
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

  Solution solution;
  solution.rotate(matrix);
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < n; ++j){
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
