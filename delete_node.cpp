//https://leetcode.com/problems/delete-node-in-a-linked-list/

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
  void deleteNode(ListNode* node) {
    if ((node == NULL) || (node->next == NULL)){
      return;
    }
    ListNode* tail;
    while(node->next){
      node->val = node->next->val;
      tail = node;
      node = node->next;
    }
    tail->next = NULL;
  }
};
