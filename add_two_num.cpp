//https://oj.leetcode.com/problems/add-two-numbers/

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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (l1 == NULL){
      return l2;
    }
    else if (l2 == NULL){
      return l1;
    }
    ListNode *head = new ListNode((l1->val+l2->val)%10);
    int andone = (l1->val+l2->val) >= 10;
    ListNode* p = head;
    while((l1->next != NULL) && (l2->next != NULL)){
      l1 = l1->next;
      l2 = l2->next;
      ListNode *now = new ListNode((l1->val + l2->val + andone)%10);
      andone = ((l1->val+l2->val)+andone) >= 10;
      p->next = now;
      p = p->next;
    }
    while(l1->next != NULL){
      l1 = l1->next;
      ListNode *now = new ListNode((l1->val+andone)%10);
      andone = (l1->val + andone) >= 10;
      p->next = now;
      p = p->next;
    }
    while(l2->next != NULL){
      l2 = l2->next;
      ListNode *now = new ListNode((l2->val+andone)%10);
      andone = (l2->val + andone) >= 10;
      p->next = now;
      p = p->next;
    }
    if (andone > 0){
      ListNode *now = new ListNode(1);
      p->next = now;
    }
    return head;
  }
};
