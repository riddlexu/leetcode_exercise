#include<iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
      int one = 0;
      int two = 0;
      int three = 0;
      for (int i = 0; i < n; i++){
        two = (one & A[i]) | two;
        one = one ^ A[i];
        three = ~(one & two);
        two = two & three;
        one = one & three;
      }
      return one;
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
