class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.size() == 0){
            return true;
        }
        if (dict.size() == 0){
          return false;
        }
        bool* f = (bool*)malloc(sizeof(bool)*s.size());
        for(int i = 0; i < s.size(); i++){
          f[i] = false;
        }
        for(int i = 0; i < s.size(); i++){
          f[i] = dict.count(s.substr(0,i+1));
          if (f[i]){
            continue;
          }
          for (int j = 0; j < i; ++j){
            if (f[j] && dict.count(s.substr(j+1,i-j))){
              f[i] = true;
              break;
            }
          }
        }
        return f[s.size() - 1];
    }
};
