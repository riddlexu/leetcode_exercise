//https://oj.leetcode.com/problems/sort-colors/

class Solution {
 public:
  void sortColors(int A[], int n) {
    int red = 0;
    int white = 0;
    int blue = 0;
    for (int i = 0; i < n; i++){
      if (A[i] == 0){
        red++;
      }
      else if (A[i] == 1){
        white++;
      }
      else {
        blue++;
      }
    }
    for (int i = 0; i < n; i++){
      if (red != 0){
        A[i] = 0;
        red--;
      }
      else if (white != 0){
        A[i] = 1;
        white--;
      }
      else {
        A[i] = 2;
        blue--;
      }
    }
  }

  void sortColors(int A[], int n) {
    int redp = 0;
    int bluep = n - 1;
    int i = 0; 
    while(i <= bluep){
      if (A[i] == 0){
        swap(A[i],A[redp]);
        redp++;
        i++;
      }
      else if (A[i] == 2){
        swap(A[i],A[bluep]);
        bluep--;
      }
      else{
        i++;
      }
    }
  }
};
