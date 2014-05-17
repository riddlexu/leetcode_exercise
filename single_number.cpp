#include<iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
      int ans;
      ans = A[0];
      for (int i = 1; i < n; i++){
        ans = ans ^ A[i];
      }
      return ans;
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
  cout << solution.singleNumber(A, n) << endl;
}
