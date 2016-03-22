class Solution {
 public:
  int firstMissingPositive(int A[], int n) {
    if (n == 0){
      return 1;
    }
    if (n == 1){
      if (A[0] == 1){
        return 2;
      }
      return 1;
    }
    int temp;
    int i = 0;
    while(i < n){
      if ((A[i] >= 1) && (A[i] <= n) && (A[i] != i+1) && (A[i] != A[A[i]-1])){
        temp = A[A[i]-1];
        A[A[i]-1] = A[i];
        A[i] = temp;
      } 
      else {
        i++;
      }
    }
    for (int i = 0; i < n; i++){
      if (A[i] != i+1){
        return i+1;
      }
    }
    return n+1;
  }
};
