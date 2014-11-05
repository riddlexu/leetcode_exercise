class Solution {
  int n;
  int m;
  std::deque<pair<int,int>> myqueue;
  void search(vector<vector<char>> &buf){
    pair<int,int> point = myqueue.front();
    myqueue.pop_front();
    int y = point.first;
    int x = point.second;
    if((y > 1) && (buf[y-1][x] == 'O')){
      buf[y-1][x] = 'T';
      myqueue.push_back(make_pair(y-1,x));
    }
    if((y < n - 2) && (buf[y+1][x] == 'O')){
      buf[y+1][x] = 'T';
      myqueue.push_back(make_pair(y+1,x));
    }
    if((x > 1) && (buf[y][x-1] == 'O')){
      buf[y][x-1] = 'T';
      myqueue.push_back(make_pair(y,x-1));
    }
    if((x < m - 2) && (buf[y][x+1] == 'O')){
      buf[y][x+1] = 'T';
      myqueue.push_back(make_pair(y,x+1));
    }
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
      if(board[0][i] == 'O'){
        board[0][i] = 'T';
        myqueue.push_back(make_pair(0,i));
      }
      if(board[n-1][i] == 'O'){
        board[n-1][i] = 'T';
        myqueue.push_back(make_pair(n-1,i));
      }
    }
    for(int i = 1; i < n - 1; i++){
      if(board[i][0] == 'O'){
        board[i][0] = 'T';
        myqueue.push_back(make_pair(i,0));
      }
      if(board[i][m-1] == 'O'){
        board[i][m-1] = 'T';
        myqueue.push_back(make_pair(i,m-1));
      }
    }
    while(!myqueue.empty()){
      search(board);
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
