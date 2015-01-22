//https://oj.leetcode.com/problems/compare-version-numbers/

class Solution {
 public:
  int compareVersion(string version1, string version2) {
    size_t p1 = version1.find('.');
    size_t p2 = version2.find('.');
    size_t d1 = 0;
    size_t d2 = 0;
    if (p1 != string::npos){
      d1 = stoi(version1.substr(0,p1));
    }
    else {
      d1 = stoi(version1);
    }
    if (p2 != string::npos){
      d2 = stoi(version2.substr(0,p2));
    }
    else {
      d2 = stoi(version2);
    }
    if (d1 > d2){
      return 1;
    }
    else if (d1 < d2){
      return -1;
    }
        
    size_t f1 = 0;
    if (p1 != string::npos){
      f1 = stoi(version1.substr(p1+1));
    }
    size_t f2 = 0;
    if (p2 != string::npos){
      f2 = stoi(version2.substr(p2+1));
    }
    if (f1 > f2){
      return 1;
    }
    else if (f1 < f2){
      return -1;
    }
    return 0;
  }
};
