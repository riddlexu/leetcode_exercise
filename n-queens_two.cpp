class Solution {
 public:
  int totalNQueens(int n) {
    int* a = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; ++i){
      a[i] = -1;
    }
    int ans = 0;
    int num = 0;
    do{
      a[num]++;
      while((a[num] < n) && !isValid(a,num)){
        a[num]++;
      }
      if (a[num] == n){
        a[num] = -1;
        num--;
      }
      else{
        if (num < n - 1){
          num++;
        }
        else{
          ans++;
        }
      }
    }while(num >= 0);
    return ans;
  }
 private:
  int isValid(int* a, int num){
    if (num == 0){
      return true;
    }
    for (int i = 0; i < num; ++i){
      if ((a[i] == a[num]) || (a[i] + i == a[num] + num) || (a[i] - i == a[num] - num)){
        return false;
      }
    }
    return true;
  }
};
