class Solution {
 private:
  static const int size = 9;
 public:
  bool isValidSudoku(vector<vector<char> > &board) {
    std::set<char> hash;
    for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
        if(board[i][j] == '.') continue;
        if(hash.count(board[i][j]) > 0){
          return false;
        }
        else {
          hash.insert(board[i][j]);
        }
      }
      hash.clear();
    }
    for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
        if(board[j][i] == '.') continue;

        if(hash.count(board[j][i]) > 0){
          return false;
        }
        else {
          hash.insert(board[j][i]);
        }
      }
      hash.clear();
    }
    for(int k = 0; k < size; k++){
      for(int i = (k/3)*3; i < (k/3 + 1)*3; i++){
        for(int j = (k%3)*3; j < (k%3 + 1)*3; j++){
          if(board[i][j] == '.') continue;
          if(hash.count(board[i][j]) > 0){
            return false;
          }
          else {
            hash.insert(board[i][j]);
          }          
        }
      }
      hash.clear();
    }
    
    return true;
  }
};
