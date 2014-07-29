//https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() < 2){
      return 0;
    }
    int min = prices[0];
    int sums = 0;
    for(int i = 1; i < prices.size(); i++){
      if (prices[i] < prices[i-1]){
        sums += prices[i-1] - min;
        min = prices[i];
      }
    }
    if (min != prices[prices.size() - 1]){
      sums += prices[prices.size() - 1] - min;
    }
    return sums;
  }
};
