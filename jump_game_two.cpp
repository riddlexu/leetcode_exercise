//https://oj.leetcode.com/problems/jump-game-ii/

class Solution {
 public:
  int jump(int A[], int n) {
    if (n <= 1){
      return 0;
    }
    int* steps;
    steps = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++){
      steps[i] = -1;
    }
    steps[0] = 0;
    for (int i = 0; i < n-1; ++i){
      if (steps[i] == -1){
        continue;
      }
      else if (i + A[i] >= n - 1){
        return steps[i] + 1;
      }
      else if ((steps[i + A[i]] > 0) && (steps[i + A[i]] < steps[i] + 1)){
        continue;
      }
      for (int j = 1; j <= A[i]; ++j){
        if ((steps[i+j] < 0) || (steps[i+j] > steps[i] + 1)){
          steps[i+j] = steps[i] + 1;
        }
      }
    }
    return steps[n-1];
  }
};
