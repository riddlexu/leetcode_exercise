#include<iostream>
using namespace std;


class Solution {
 public:
  int climbStairs(int n) {
    int a,b,c;
    if (n == 1){
      return 1;
    }
    if (n == 2){
      return 2;
    }
    a = 1;
    b = 2;
    for (int i = 3; i <= n; i++){
      c = a + b;
      a = b;
      b = c;
    }
    return c;
  }
};


int main()
{
  int n;
  cin >> n;
  Solution solution;
  cout << solution.climbStairs(n) << endl;
  return 0;
}
