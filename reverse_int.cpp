#include<iostream>
using namespace std;

class Solution {
 public:
  int reverse(int x) {
    if (x == 0){
      return 0;
    }
    int ans = 0;
    while(x != 0){
      ans = ans * 10 + x % 10;
      x = x / 10;
    }
    return ans;
  }
};
int main()
{
  Solution solution;
  int x;
  cin >> x;
  cout << solution.reverse(x) << endl;
  return 0;
}
