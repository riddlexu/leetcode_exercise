//https://oj.leetcode.com/problems/combinations/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
 public:
  vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > ans;
    vector<int> half;
    combine_rec(ans, half, 0, n, k);
    return ans;
  }
  
  void combine_rec(vector<vector<int> > &ans, vector<int> half, int start, int n, int k){
    if (k == 0){
      ans.push_back(half);
      return;
    }
    else if (start >= n){
      return;
    }
    for (int i = start + 1; i <= n; i++){
      vector<int> new_half = half;
      new_half.push_back(i);
      combine_rec(ans,new_half,i,n,k-1);
    }
  }
};

int main()
{
  int n,k;
  cin >> n >> k;
  Solution solution;
  vector<vector<int> > ans = solution.combine(n,k);
}
