//https://leetcode.com/problems/reverse-linked-list/

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
  ListNode* reverseList(ListNode* head) {
    if(head == NULL){
      return head;
    }
    ListNode* newlist = head;
    ListNode* oldlist = head->next;
    newlist->next = NULL;
    while(oldlist){
      ListNode* tmp = oldlist;
      oldlist = oldlist->next;
      tmp->next = newlist;
      newlist = tmp;
    }
    return newlist;
  }
};
