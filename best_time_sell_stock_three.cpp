//https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() < 2){
      return 0;
    }
    int* forward = (int*)malloc(sizeof(int)*prices.size());
    int* backward = (int*)malloc(sizeof(int)*prices.size());
    
    //forward pass
    int min = prices[0];
    int profit = 0;
    forward[0] = 0;
    for (int i = 1; i < prices.size(); ++i){
      if (prices[i] - min > profit){
        profit = prices[i] - min;
      }
      else if (prices[i] < min){
        min = prices[i];
      }
      forward[i] = profit;
    }
    
    //backward pass
    backward[prices.size() - 1] = 0;
    int max = prices.back();
    profit = 0;
    for (int i = prices.size() - 2; i >= 0; --i){
      if (max - prices[i] > profit){
        profit = max - prices[i];
      }
      else if(prices[i] > max){
        max = prices[i];
      }
      backward[i] = profit;
    }

    //finish
    int ans = std::max(forward[prices.size()-1],backward[0]);
    for (int i = 0; i < prices.size() - 1; ++i){
      if (ans < forward[i] + backward[i+1]){
        ans = forward[i] + backward[i+1];
      }
    }
    free(forward);
    free(backward);
    return ans;
  }
};

