//https://oj.leetcode.com/problems/unique-binary-search-trees/

class Solution {
 public:
  int numTrees(int n) {
    int* h;
    h = (int*)malloc(sizeof(int)*(n+1));
    h[0] = 1;
    h[1] = 1;
    for (int i = 2; i <= n; ++i){
      h[i] = 0;
      for (int j = 1; j <= i; ++j){
        h[i] += h[j-1]*h[i-j];
      }
    }
    return h[n];
  }
};
