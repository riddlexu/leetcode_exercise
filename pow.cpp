#include<iostream>

using namespace std;

class Solution {
 public:
  double pow(double x, int n) {
    if (n == 0){
      return 1;
    }
    if (n == 1){
      return x;
    }
    bool positive = true;

    if (n < 0){
      n = -n;
      positive = false;
    }
    
    double table[65];
    table[0] = 1.0;
    table[1] = x;
    unsigned int tag[65];
    tag[0] = 0;
    tag[1] = 1;
    unsigned int top;
    for (unsigned int i = 2; i < 65; i++){
      tag[i] = 2 * tag[i-1];
      table[i] = table[i-1]*table[i-1];
      if (tag[i] > n){
        top = i - 1;
        break;
      }
      else if (tag[i] == n){
        top = i;
        break;
      }
    }
    double base = 1.0;
    for (unsigned int i = top; i > 0; i--){
      if (n >= tag[i]){
        n = n - tag[i];
        base = base * table[i];
      }
      if (n == 0){
        break;
      }
    }

    if (!positive){
      base = 1.0 / base;
    }
    return base;
  }
};

int main()
{
  int n;
  double x;
  cin >> x >> n;
  Solution solution;
  cout << solution.pow(x,n) << endl;
  return 0;
}
