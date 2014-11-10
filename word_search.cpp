//https://oj.leetcode.com/problems/word-search/

class Solution {
  vector<vector<bool> > flag;
  int height;
  int width;
  bool search(vector<vector<char> > &board, int y, int x, string word){
    flag[y][x] = false;
    if(word == ""){
      return true;
    }
    if((x > 0) && (word[0] == board[y][x-1]) && flag[y][x-1]){
      if(search(board,y,x-1,word.substr(1))){
        return true;
      }
    }
    if((x < width - 1) && (word[0] == board[y][x+1]) && flag[y][x+1]){
      if(search(board,y,x+1,word.substr(1))){
        return true;
      }
    }
    if((y > 0) && (word[0] == board[y-1][x]) && flag[y-1][x]){
      if(search(board,y-1,x,word.substr(1))){
        return true;
      }
    }
    if((y < height - 1) && (word[0] == board[y+1][x]) && flag[y+1][x]){
      if(search(board,y+1,x,word.substr(1))){
        return true;
      }
    }
    flag[y][x] = true;
    return false;
  }
 public:
  bool exist(vector<vector<char> > &board, string word) {
    if(word == ""){
      return true;
    }
    height = board.size();
    if(height == 0){
      return false;
    }
    width = board[0].size();
    if(width == 0){
      return false;
    }
    for(int i = 0; i < height; i++){
      vector<bool> tmp;
      for(int j =0; j < width; j++){
        tmp.push_back(true);
      }
      flag.push_back(tmp);
    }
    for(int i = 0; i < height; i++){
      for(int j = 0; j < width; j++){
        if((word[0] == board[i][j]) && (search(board,i,j,word.substr(1)))){
          return true;
        }
      }
    }
    return false;
  }
};
