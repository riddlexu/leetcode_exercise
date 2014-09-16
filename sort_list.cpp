//https://oj.leetcode.com/problems/sort-list/
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
  ListNode *sortList(ListNode *head) {
    ListNode* tail = head;
    while((tail != NULL) && (tail->next != NULL)){
      tail = tail->next;
    }
    if (tail == head){
      return head;
    }
    int cmp = tail->val;
    ListNode* mid = head;
    ListNode* now = head;
    ListNode* premid = NULL;
    while(now != tail){
      if (now->val < cmp){
        if (mid != now){
          swap(now->val,mid->val);
        }
        premid = mid;
        mid = mid->next;
      }
      now = now->next;
    }
    swap(mid->val,tail->val);
    if (premid){
      premid->next = NULL;
      sortList(head);
      premid->next = mid;
    }
        
    if (mid != tail){
      sortList(mid->next);
    }
    return head;
  }
};
