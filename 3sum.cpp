class Solution {
 public:
  vector<vector<int> > threeSum(vector<int> &num) {
    std::sort(num.begin(),num.end());
    vector<vector<int> > ans;
    if (num.size() < 3){
      return ans;
    }
    vector<int> sol;
    for(int i = 0; i < num.size() - 2; i++){
      if (num[i] > 0){
        break;
      }
      if ((i != 0) && (num[i] == num[i-1])){
        continue;
      }
      int left = i+1;
      int right = num.size() - 1;
      while(left < right){
        int res = num[left] + num[right];
        if (res + num[i] == 0){
          sol.push_back(num[i]);
          sol.push_back(num[left]);
          sol.push_back(num[right]);
          ans.push_back(sol);
          do{
            left++;
          }
          while((left < right) && (num[left - 1] == num[left]));
          do{
            right--;
          }
          while((left < right) && (num[right] == num[right+1]));

          sol.clear();
        }
        else if (res + num[i] < 0){
          do{
            left++;
          }
          while((left < right) && (num[left - 1] == num[left]));
        }
        else {
          do{
            right--;
          }
          while((left < right) && (num[right] == num[right+1]));
        }
      }
    }
    return ans;
  }
};
