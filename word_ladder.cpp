class Solution {
 public:
  int ladderLength(string start, string end, unordered_set<string> &dict) {
    int tail = start.size() - 1;
    if(start[tail] == end[0]){
      return 2;
    }
    deque<string> parent;
    deque<string> son;
    parent.push_back(start);
    int distance = 1;
    while(!dict.empty()){
      while(!parent.empty()){
        string now = parent.front();
        if(now[tail] == end[0]){
          return distance + 1;
        }
        parent.pop_front();
      }
      swap(parent,son);
      distance++;
    }
    return 0;
  }
};
