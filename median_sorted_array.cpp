//https://oj.leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
 public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int all = m + n;
    if (all % 2 == 1){
      return findKth(A,m,B,n,all / 2 + 1);
    }
    else {
      return (findKth(A,m,B,n,all / 2) + findKth(A,m,B,n,all / 2 + 1)) / 2.0;
    }
  }
  double findKth(int A[], int m, int B[], int n, int target){
    if (m < n){
      return findKth(B,n,A,m,target);
    }
    if (n == 1){
      if (target == m + 1){
        return std::max(A[m-1],B[0]);
      }
      else if (target == 1){
        return std::min(A[0],B[0]);
      }
      else{
        return std::max(std::min(A[target-1],B[0]),A[target-2]);
      }
    }
    else if (n == 0){
      return A[target-1];
    }
    else{
      int indexA,indexB;
      if (target / 2 > n){
        indexB = n - 1;
        indexA = target - n + 1;
      }
      else{
        if (target % 2 == 0){
          indexA = target / 2;
          indexB = indexA;
        }
        else{
          indexB = target / 2;
          indexA = indexB + 1;
        }
      }
      if (A[indexA-1] > B[indexB-1]){
        B = B + indexB;
        return findKth(A,indexA,B,n-indexB,target-indexB);
      }
      else if (A[indexA-1] == B[indexB-1]){
        return A[indexA-1];
      }
      else{
        A = A + indexA;
        return findKth(A,m-indexA,B,indexB,target-indexA);
      }
      
    }
  }
};
