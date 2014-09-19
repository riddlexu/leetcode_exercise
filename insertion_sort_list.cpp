//https://oj.leetcode.com/problems/insertion-sort-list/

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
  ListNode *insertionSortList(ListNode *head) {
    ListNode* p;
    if (head == NULL){
      return head;
    }
    p = head->next;
    head->next = NULL;
    while(p != NULL){
      ListNode* newele = p;
      p = p->next;
      newele->next = NULL;
      if (newele->val < head->val){
        newele->next = head;
        head = newele;
      }
      else {
        ListNode* tmp = head;
        while(tmp->next){
          if (newele->val < (tmp->next)->val){
            newele->next = tmp->next;
            tmp->next = newele;
            break;
          }
          tmp = tmp->next;
        }
        if (tmp->next == NULL){
          tmp->next = newele;
        }
      }
    }
    return head;
  }
};
