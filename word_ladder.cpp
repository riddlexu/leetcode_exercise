class Solution {
 public:
  int ladderLength(string start, string end, unordered_set<string> &dict) {
    int tail = start.size() - 1;
    if(start == end){
      return 1;
    }
    deque<string> parent;
    deque<string> son;
    parent.push_back(start);
    int distance = 1;
    while(!dict.empty()){
      while(!parent.empty()){
        string now = parent.back();
        for(int i = 0; i < now.size(); i++){
          for(char j = 'a'; j <= 'z'; j++){
            if(now[i] != j){
              string tmp = now;
              tmp[i] = j;
              if(tmp == end){
                  return distance+1;
              }
              else if(dict.count(tmp) > 0){
                dict.erase(tmp);
                son.push_back(tmp);
              }
            }
          }
        }
        parent.pop_back();
      }
      if(son.empty()){
          return 0;
      }
      swap(parent,son);
      distance++;
    }
    return 0;
  }
};
