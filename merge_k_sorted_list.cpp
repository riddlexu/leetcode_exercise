//https://oj.leetcode.com/problems/merge-k-sorted-lists/

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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if(lists.size() == 0){
      return NULL;
    } 
    if(lists.size() == 1){
      return lists[0];
    }
    if(lists.size() == 2){
      return merge(lists[0],lists[1]);
    }
    vector<ListNode *> left;
    vector<ListNode *> right;
    int mid = lists.size() / 2;
    for(int i = 0; i < mid; i++){
      left.push_back(lists[i]);
    }
    for(int i = mid; i < lists.size(); i++){
      right.push_back(lists[i]);
    }
    return merge(mergeKLists(left),mergeKLists(right));
       
  }
  ListNode* merge(ListNode* list1, ListNode* list2){
    ListNode* head;
    if(!list1){
      return list2;
    }
    if(!list2){
      return list1;
    }
    if(list1->val < list2->val){
      head = list1;
      list1 = list1->next;
    }
    else{
      head = list2;
      list2 = list2->next;
    }
    ListNode* p = head;
    while((list1 != NULL) && (list2 != NULL)){
      if(list1->val < list2->val){
        p->next = list1;
        list1 = list1->next;
      }
      else{
        p->next = list2;
        list2 = list2->next;
      }
      p = p->next;
    }
    if(list1 != NULL){
      p->next = list1;
    }
    else{
      p->next = list2;
    }
    return head;
  }
};
