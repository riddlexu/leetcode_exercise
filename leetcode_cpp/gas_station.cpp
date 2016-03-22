//https://oj.leetcode.com/problems/gas-station/

class Solution {
 public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int res = 0;
    int all = 0;
    int loc = 0;
    for(int i = 0; i < cost.size(); i++){
      all += gas[i] - cost[i];
      res += gas[i] - cost[i];
      if(res < 0){
        loc = i + 1;
        res = 0;
      }
    }
    if(all < 0){
      return -1;
    }
    return loc;
  }
};
