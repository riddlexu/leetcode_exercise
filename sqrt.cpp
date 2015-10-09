#include<iostream>
#include<algorithm>
#include<stdlib.h>

using namespace std;

class Solution {
 public:
  int sqrt(int x) {
    if (x == 0){
      return 0;
    }
    if (x == 1){
      return 1;
    }
    int guess = 2;
    int next_guess = x / guess;

    while(abs(next_guess-guess) > 1){
      guess = (next_guess + guess)/2;
      next_guess = x / guess;
    }
    return min(next_guess, guess);
  }
};

int main()
{
  int n;
  cin >> n;
  Solution solution;
  cout << solution.sqrt(n) << endl;
  return 0;
}


