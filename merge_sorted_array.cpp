#include<iostream>
using namespace std;

class Solution {
 public:
  void merge(int A[], int m, int B[], int n) {
    if (n == 0){
      return;
    }
    if (m == 0){
      for (int i = 0; i < n; ++i){
        A[i] = B[i];
      }
      return;
    }
    for (int i = m - 1; i >= 0; i--){
      A[i+n] = A[i];
    }
    int a_index = 0;
    int b_index = 0;
    while((a_index < m) || (b_index < n)){
      if (A[a_index + n] <= B[b_index]){
        A[a_index+b_index] = A[a_index + n];
        a_index++;
      }
      else{
        A[a_index+b_index] = B[b_index];
        b_index++;        
      }
      if (a_index == m){
        for (int i = b_index; i < n; i++){
          A[m+i] = B[i];
        }
        return;
      }
      else if (b_index == n){
        return;
      }
    }
  }
};

int main()
{
  int m,n;
  cin >> m >> n;
  int* A;
  A = (int*)malloc(sizeof(int)*m);
  for (int i = 0; i < m; i++){
    cin >> A[i];
  }

  int* B;
  B = (int*)malloc(sizeof(int)*n);
  for (int i = 0; i < n; i++){
    cin >> B[i];
  }
  
  Solution solution;
  solution.merge(A,m,B,n);

  for (int i = 0; i < m+n; i++){
    cout << A[i] << " ";
  }
  cout << endl;
  return 0;
}
