#include<iostream>
using namespace std;

class Solution {
 public:
  int removeElement(int A[], int n, int elem) {
    int loc = 0;
    for (int i = 0; i < n; i++){
      if (A[i] != elem){
        A[loc] = A[i];
        loc++;
      }
    }
    return loc;
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
  int elem;
  cin >> elem;
  
  Solution solution;
  cout << solution.removeElement(A,n,elem) << endl;
}

