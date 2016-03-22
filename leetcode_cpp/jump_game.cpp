#include<iostream>
using namespace std;

class Solution {
 public:
  bool canJump(int A[], int n) {
    if (n <= 1){
      return true;
    }
    bool* B;
    B = (bool*)malloc(sizeof(bool)*n);
    for (int i = 0; i < n; ++i){
      B[i] = false;
    }
    B[0] = true;
    for (int i = 0; i < n-1; ++i){
      if (!B[i]){
        continue;
      }
      else if (i + A[i] >= n - 1){
        return true;
      }
      else if (B[i + A[i]]){
        continue;
      }
      for (int j = 1; j <= A[i]; ++j){
        B[i+j] = true;
      }
    }
    return B[n-1];
  }
};

int main()
{
  int n;
  cin >> n;

  int* A;
  A = (int*)malloc(sizeof(int)*n);
  for (int i = 0; i < n; i++){
    cin >> A[i];
  }
  
  Solution solution;
  cout << solution.canJump(A,n) << endl;
}
