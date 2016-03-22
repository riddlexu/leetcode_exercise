#include<iostream>
using namespace std;

class Solution {
 public:
  int removeDuplicates(int A[], int n) {
    if (n <= 1){
      return n;
    }
    int front = 0;
    int end = 1;
    while(end < n){
      if (A[front] == A[end]){
        end++;
      }
      else if (end - 1 > front){
        front++;
        A[front] = A[end];
        end++;
      }
      else {
        front++;
        end++;
      }
    }
    return front+1;
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

