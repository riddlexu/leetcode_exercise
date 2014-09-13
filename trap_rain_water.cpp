class Solution {
 public:
  int trap(int A[], int n) {
    if (n < 3){
      return 0;
    }
    int ans = 0;
    int* left = (int*)malloc(sizeof(int)*n);
    int* right = (int*)malloc(sizeof(int)*n);
    left[0] = A[0];
    right[n-1] = A[n-1];
    for (int i = 1; i < n; i++){
      left[i] = std::max(left[i-1],A[i]);
    }

    for (int i = n - 2; i >= 0; --i){
      right[i] = std::max(right[i+1],A[i]);
    }

    for (int i = 1; i < n - 1; i++){
      ans += std::min(left[i],right[i]) - A[i];
    }
    
    free(left);
    free(right);
    return ans;
  }
};
