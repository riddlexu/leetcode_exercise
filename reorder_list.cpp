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
  void reorderList(ListNode *head) {
    if ((head == NULL) || (head->next == NULL)){
      return;
    }
    ListNode* p = head->next;
    int length = 0;
    while(p != NULL){
      length++;
      p = p->next;
    }
    if (length <= 1){
      return;
    }
    int mid = length / 2;
    ListNode* straight = head->next;
    ListNode* reverse = head;

    for (int i = 0; i < mid; i++){
      reverse = reverse->next;
    }
    p = reverse;
    reverse = reverse->next;
    p->next = NULL;

    //reverse list
    ListNode* newele = reverse->next;
    reverse->next = NULL;
    while(newele != NULL){
      p = newele->next;
      newele->next = reverse;
      reverse = newele;
      newele = p;
    }

    p = head;
    for (int i = 0; i < mid; i++){
      p->next = reverse;
      reverse = reverse->next;
      p = p->next;
      p->next = straight;
      straight = straight->next;
      p = p->next;
    }
    if (length % 2 == 1){
      p->next = reverse;
    }
  }
};


