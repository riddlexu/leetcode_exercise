class Solution {
 public:
  vector<string> anagrams(vector<string> &strs) {
    vector<string> ans;
    if(strs.size() < 2){
      return ans;
    }
    unordered_map<string,string> hash;
    for (int i = 0; i < strs.size(); ++i){
      string tmp = strs[i];
      std::sort(tmp.begin(),tmp.end());
      if(hash.count(tmp) > 0){
        if(hash[tmp] != " "){
          ans.push_back(hash[tmp]);
          hash[tmp] = " ";
        }
        ans.push_back(strs[i]);
      }
      else{
        hash.insert(make_pair(tmp,strs[i]));
      }
    }
    return ans;
  }
};
