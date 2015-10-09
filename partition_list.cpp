/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
 public:
  ListNode *partition(ListNode *head, int x) {
    if((head == NULL) || (head->next == NULL)){
      return head;
    }
    ListNode* large_head = NULL;
    ListNode* small_head = NULL;
    ListNode* large_tail = NULL;
    ListNode* small_tail = NULL;
    ListNode* p = head;

    while(p){
      if (p->val >= x){
        if(large_head){
          large_tail->next = p;
        }
        else{
          large_head = p;
        }
        large_tail = p;
      }
      else {
        if(small_head){
          small_tail->next = p;
        }
        else{
          small_head = p;
        }
        small_tail = p;
      }
      p = p->next;
    }
    if(small_tail){
      small_tail->next = large_head;
      if(large_head){
        large_tail->next = NULL;
      }
      return small_head;
    }
    return large_head;
  }
};
