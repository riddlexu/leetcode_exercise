class Solution {
  int n;
  int m;
  void search(int y, int x, vector<vector<char>> &buf){
    if((y < 0) || (y >= n) || (x < 0) || (x >= m) || (buf[y][x] != 'O')){
      return;
    }
    buf[y][x] = 'T';
    search(y-1,x,buf);
    search(y+1,x,buf);
    search(y,x-1,buf);
    search(y,x+1,buf);
  }
 public:
  void solve(vector<vector<char>> &board) {
    n = board.size();
    if(n == 0){
      return;
    }
    m = board[0].size();
    if(m == 0){
      return;
    }
    for(int i = 0; i < m; i++){ 
      search(0,i,board);
      search(n-1,i,board);
    }
    for(int i = 1; i < n - 1; i++){
      search(i,0,board);
      search(i,m-1,board);
    }
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(board[i][j] == 'T'){
          board[i][j] = 'O';
        }
        else if(board[i][j] == 'O'){
          board[i][j] = 'X';
        }
      }
    }
  }
};
