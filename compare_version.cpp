//https://oj.leetcode.com/problems/compare-version-numbers/

class Solution {
 public:
  int compareVersion(string version1, string version2) {
    vector<int> ans1;
    vector<int> ans2;
    string s1 = version1;
    string s2 = version2;
    
    size_t p1 = s1.find('.');
    while(p1 != string::npos){
      ans1.push_back(stoi(s1.substr(0,p1)));
      s1 = s1.substr(p1+1);
      p1 = s1.find('.');
    }
    ans1.push_back(stoi(s1));

    size_t p2 = s2.find('.');
    while(p2 != string::npos){
      ans2.push_back(stoi(s2.substr(0,p2)));
      s2 = s2.substr(p2+1);
      p2 = s2.find('.');
    }
    ans2.push_back(stoi(s2));
    int i = 0;
    for(i = 0; i < min(ans1.size(),ans2.size()); i++){
      if(ans1[i] < ans2[i]){
        return -1;
      }
      else if (ans1[i] > ans2[i]){
        return 1;
      }
    }
    if(i < ans1.size()){
      for(int j = i; j < ans1.size(); j++){
        if(ans1[j] != 0){
          return 1;
        }
      }
    }
    else if (i < ans2.size()){
      for(int j = i; j < ans2.size(); j++){
        if(ans2[j] != 0){
          return -1;
        }
      }

    }
    return 0;
  }
};
