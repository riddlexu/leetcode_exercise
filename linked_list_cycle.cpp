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
    if (head == NULL){
      return false;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    do{
      slow = slow->next;
      if (slow == NULL){
        return false;
      }
      fast = fast->next;
      if (fast == NULL){
        return false;
      }
      fast = fast->next;
      if (fast == NULL){
        return false;
      }
      if (fast == slow){
        return true;
      }
    }
    while(true);
  }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }
        if(head->next == NULL){
            return false;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
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
