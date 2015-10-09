//https://oj.leetcode.com/problems/copy-list-with-random-pointer/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
 public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if(head == NULL){
      return NULL;
    }
    RandomListNode* p = head;
    while(p){
      RandomListNode* tmp = new RandomListNode(p->label);
      tmp->next = p->next;
      p->next = tmp;
      p = tmp->next;
    }
    p = head;
    while(p){
      if(p->random){
        (p->next)->random = (p->random)->next;
      }
      p = (p->next)->next;
    }
    RandomListNode* ans = head->next;
    p = head;
    RandomListNode* q = head->next;
    while(p){
      p->next = q->next;
      p = p->next;
      if(p){
        q->next = p->next;
        q = q->next;
      }
    }
    return ans;
  }
};
