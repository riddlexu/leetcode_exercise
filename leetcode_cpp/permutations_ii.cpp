//https://oj.leetcode.com/submissions/detail/15553657/

class Solution {
 private:
  vector<vector<int> > search(vector<int> &num){
    vector<vector<int> > ans;
    if(num.size() == 0){
      return ans;
    }
    else if(num.size() == 1){
      vector<int> tmp;
      tmp.push_back(num[0]);
      ans.push_back(tmp);
      return ans;
    }
    int val;
    for(int i = 0; i < num.size(); i++){
      if(i == 0){
        val = num[i];
      }
      else if(num[i] == val){
        continue;
      }
      else{
        val = num[i];
      }
      num.erase(num.begin()+i);
      vector<vector<int> > sols = search(num);
      num.insert(num.begin()+i,val);
      if(sols.size() > 0){
        for(int j = 0; j < sols.size(); j++){
          sols[j].push_back(val);
          ans.push_back(sols[j]);
        }
      }
      //not swap back. It's the point!!!
    }
    return ans;
  }
 public:
  vector<vector<int> > permuteUnique(vector<int> &num) {
    sort(num.begin(),num.end());
    return search(num);
  }
};
