#include<iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    
  }
};


int main()
{
  Solution solution;
  ListNode list(1);
  ListNode list2(2);
  ListNode* listpoint = &list;
  listpoint->next = &list2;
  cout << solution.hasCycle(listpoint) << endl;
  return 0;
}
