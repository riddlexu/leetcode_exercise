#include<iostream>
using namespace std;

class Solution {
 public:
  int removeDuplicates(int A[], int n) {
    if (n <= 2){
      return n;
    }
    int loc = 1;
    for (int i = 2; i < n; i++){
      if ((A[loc] == A[i]) && (A[loc-1] == A[loc])){
        
      }
      else{
        loc++;
        A[loc] = A[i];
      }
    }
    return loc + 1;
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
