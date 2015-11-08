//https://leetcode.com/problems/valid-anagram/

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()){
      return false;       
    }
    unordered_map<char, int> mymap;
    for (int i = 0; i < s.size(); i++){
      if (mymap.count(s[i]) > 0){
	mymap[s[i]] = mymap[s[i]] + 1;
      } else {
	mymap.insert(make_pair(s[i],1));
      }
    }
    for (int i = 0; i < t.size(); i++){
      if (mymap.count(t[i]) > 0){
	mymap[t[i]] = mymap[t[i]] - 1; 
      } else {
	return false;
      }
    }
    for (int i = 0; i < s.size(); i++){
      if (mymap[s[i]] != 0) {
	return false;	            
      }
    }
    return true;     
  }
};
