//https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/

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
  ListNode *removeNthFromEnd_twopass(ListNode *head, int n) {
    int length = getlength(head);
    int loc = length - n;
    if (loc == 0){
      return head->next;
    }
    ListNode* temp = head;
    while(loc > 1){
      temp = temp->next;
      loc--;
    }
    temp->next = (temp->next)->next;
    return head;
  }
  int getlength(ListNode *head){
    if (head == NULL){
      return 0;
    }
    return 1 + getlength(head->next);
  }
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    int ans = onepass(head,head->next, n, 1);
    if (ans == -1){
      return head->next;
    }
    return head;
  }
  int onepass(ListNode *prev, ListNode *head, int n, int length){
    if (head == NULL){
      if (length == n){
        return -1;
      }
      else {
        return 1;
      }
    }
    int loc = onepass(head, head->next, n, length + 1);
    if (loc < 0){
      return loc;
    }
    if (loc == n){
      prev->next = head->next;
      return -2;
    }
    return loc + 1;
  }
};
