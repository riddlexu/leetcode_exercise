/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
  *returnSize = num + 1;
  int* ans = malloc((num+1)*sizeof(int));
  ans[0] = 0;
  if (num == 0) {
    return ans;
        
  }
  ans[1] = 1;
  for (int i = 2; i <= num; i++) {
    ans[i] = ans[i/2] + i % 2;
        
  }
  return ans;
  
}
