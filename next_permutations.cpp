#include<iostream>
#include<vector>
using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int> &num) {
        
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
  solution.permute(num);
  for (unsigned int i = 0; i < num.size(); i++){
    cout << num[i] << endl;
  }
}


