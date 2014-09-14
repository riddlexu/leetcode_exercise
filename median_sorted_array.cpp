//https://oj.leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
 public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int all = m + n;
    if (all % 2 == 1){
      return findKth(A,m,B,n,all / 2 + 1);
    }
    else {
      return findKth(A,m,B,n,all / 2) + findKth(A,m,B,n,all / 2 + 1);
    }
  }
  double findKth(int A[], int m, int B[], int n, int target){
    int loc = target / 2;
    if (A[loc] > B[loc])
    return ans;
  }
};
