//https://oj.leetcode.com/problems/merge-two-sorted-lists/

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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == NULL){
      return l2;
    }
    if (l2 == NULL){
      return l1;
    }
    
    ListNode* root;
    ListNode* listp;
    if (l1->val < l2->val){
      root = l1;
      l1 = l1->next;
    }
    else{
      root = l2;
      l2 = l2->next;
    }
    listp = root;
    while((l1 != NULL) && (l2 != NULL)){
      if (l1->val < l2->val){
        listp->next = l1;
        listp = listp->next;
        l1 = l1->next;
      }
      else{
        listp->next = l2;
        listp = listp->next;
        l2 = l2->next;
      }
    }    
    if (l1 == NULL){
      listp->next = l2;
    }
    if (l2 == NULL){
      listp->next = l1;
    }
    return root;
  }
};
