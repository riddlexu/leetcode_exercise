class Solution {
public:
  int hIndex(vector<int>& citations) {
    for(int i = citations.size(); i > 0; i--) {
      if (citations.size() - i >= citations[i - 1]) {
	return citations.size() - i;
      }
    }
    return citations.size();
  }
};
