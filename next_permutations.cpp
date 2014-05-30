#include<iostream>
#include<vector>
using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int> &num) {
    bool flag = false;
    int loc;
    if (num.size() == 0){
      return;
    }
    for (unsigned int i = num.size() - 1; i > 0; i--){
      if (num[i] > num[i-1]){
        loc = i;
        flag = true;
        break;
      }
    }
    int temp;
    unsigned int start;
    unsigned int end;
    if (flag){
      temp = num[loc];
      num[loc] = num[loc-1];
      num[loc-1] = temp;
      start = loc + 1;
      end = num.size() - 1;
      while(start < end){
        temp = num[start];
        num[start] = num[end];
        num[end] = temp;
        start++;
        end--;
      }

    }
    else{
      start = 0;
      end = num.size() - 1;
      while(start < end){
        temp = num[start];
        num[start] = num[end];
        num[end] = temp;
        start++;
        end--;
      }
    }
  }
};

int main()
{
  int n,temp;
  cin >> n;
  vector<int> num;
  for (int i = 0; i < n; i++){
    cin >> temp;
    num.push_back(temp);
  }
  Solution solution;
  solution.nextPermutation(num);
  for (unsigned int i = 0; i < num.size(); i++){
    cout << num[i];
  }
}


