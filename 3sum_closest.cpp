class Solution {
 public:
  int threeSumClosest(vector<int> &num, int target) {
    int ans;
    if (num.size() < 3){
      return 0; 
    } 
    ans = num[0] + num[1] + num[2];
    if (num.size() == 3){
      return ans;
    }
    sort(num.begin(),num.end());
    for(int i = 0; i < num.size() - 2; i++){
      int left = i + 1;
      int right = num.size() - 1;
      while(left < right){
        int sum = num[i] + num[left] + num[right];
        if (sum == target){
          return target;
        }
        else if (abs(sum-target) < abs(ans-target)){
          ans = sum;
        }
        else if (sum <= target){
          left++;
        }
        else{
          right--;
        }
                
      }
    }
    return ans;
  }
};
