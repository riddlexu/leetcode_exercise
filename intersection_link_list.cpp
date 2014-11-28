//https://oj.leetcode.com/problems/intersection-of-two-linked-lists/

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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if((headA == NULL) || (headB == NULL)){
      return NULL;
    }
    int lenA = 1;
    int lenB = 1;
    ListNode* pa = headA;
    ListNode* pb = headB;
    while(pa->next){
      lenA++;
      pa = pa->next;
    }
    while(pb->next){
      lenB++;
      pb = pb->next;
    }
    if(pa != pb){
      return NULL;
    }
    
    if(lenA > lenB){
      for(int i = 0; i < lenA - lenB; i++){
        headA = headA->next;
      }
    }
    else {
      for(int i = 0; i < lenB - lenA; i++){
        headB = headB->next;
      }
    }
    while(headA != headB){
      headA = headA->next;
      headB = headB->next;
    }
    return headA;
  }
};
