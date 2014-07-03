//https://oj.leetcode.com/problems/n-queens/

class Solution {
 public:
  vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > ans;
    if (n <= 0){
      return ans;
    }
    string empty(n,'.');
    vector<string> now;
    int* x_array = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; ++i){
      x_array[i] = -1;
    }
    int num = 0;
    do{
      x_array[num]++;
      while((x_array[num] < n) && !isVaild(now,x_array[num])){
        x_array[num]++;
      }
      if (x_array[num] == n){
        x_array[num] = -1;
        num--;
        if (now.size() > 0){
          now.pop_back();
        }
      }
      else{
        now.push_back(empty);
        now[num][x_array[num]] = 'Q';
        num++;
        if (num == n){
          ans.push_back(now);
          num--;
          now.pop_back();
        }
      }
    }while (num >= 0);
    return ans;
  }
 private:
  bool isVaild(vector<string> now, int loc){
    if (now.size() == 0){
      return true;
    }
    for (int i = 0; i < now.size(); ++i){
      if (now[i][loc] == 'Q'){
        return false;
      }
    }
    int l_cross = now.size() - loc;
    for (int i = now.size() - 1; i >= 0; --i){
      if (i - l_cross >= 0){
        if (now[i][i - l_cross] == 'Q'){
          return false;
        }
      }
      else{
        break;
      }
    }
    int r_cross = now.size() + loc;
    for (int i = now.size()-1; i >= 0; --i){
      if (r_cross - i < now[i].size()){
        if (now[i][r_cross - i] == 'Q'){
          return false;
        }
      }
      else{
        break;
      }
    }
    return true;
  }
};


