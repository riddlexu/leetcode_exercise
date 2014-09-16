//https://oj.leetcode.com/problems/reverse-linked-list-ii/

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
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode* prev;
    ListNode* left;
    ListNode* right;
    ListNode* now;
    if (m == n){
      return head;
    }
    prev = head;
    for(int i = 1; i < m - 1; i++){
      prev = prev->next;
    }
        
    if (m == 1){
      right = head;
      left = head;
      now = head->next;
      prev = NULL;
    }
    else{
      left = prev->next;
      right = prev->next;
      now = left->next;
    }
        
    for(int i = m; i < n; i++){
      ListNode* temp = now->next;
      now->next = left;
      left = now;
      now = temp;
    }
    right->next = now;
    if (prev){
      prev->next = left;
      return head;
    }
    else{          
      return left;
    }
  }
};
