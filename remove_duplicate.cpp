#include<iostream>
using namespace std;

class Solution {
 public:
  int removeDuplicates(int A[], int n) {
        
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
  cout << solution.removeDuplicates(A,n) << endl;
}

