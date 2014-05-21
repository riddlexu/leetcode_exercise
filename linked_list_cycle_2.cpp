#include<iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    if (head == NULL){
      return NULL;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    bool flag = false;
    do{
      slow = slow->next;
      if (slow == NULL){
        return NULL;
      }
      fast = fast->next;
      if (fast == NULL){
        return NULL;
      }
      fast = fast->next;
      if (fast == NULL){
        return NULL;
      }
      if (fast == slow){
        flag = true;
      }
    }
    while(!flag);
    ListNode* a = head;
    ListNode* b = slow;
    while(a != b){
      a = a->next;
      b = b->next;
    }
    return a;
  }
};


int main()
{
  Solution solution;
  ListNode list(1);
  ListNode list2(2);
  ListNode* listpoint = &list;
  listpoint->next = &list2;
  cout << solution.detectCycle(listpoint) << endl;
  return 0;
}
