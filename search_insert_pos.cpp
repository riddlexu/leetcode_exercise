#include<iostream>
using namespace std;

class Solution {
 public:
  int searchInsert(int A[], int n, int target) {
    if (target <= A[0]){
      return 0;
    }
    else if (target > A[n-1]){
      return n;
    }
    int left = 0;
    int right = n;
    int middle; 
    while(left + 1 < right){
      middle = (left + right)/2;
      if (A[middle] == target){
        return middle;
      }
      else if (A[middle] > target){
        right = middle;
      }
      else{
        left = middle;
      }
    }    
    return left + 1;
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
  int target;
  cin >> target;
  
  Solution solution;
  cout << solution.searchInsert(A,n,target) << endl;
}

