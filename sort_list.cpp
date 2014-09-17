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
  ListNode *quicksortList(ListNode *head) {
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
  ListNode *sortList(ListNode *head) {
    ListNode* p = head;
    int i = 0;
    while(p){
      i++;
      p = p->next;
    }
    if (i <= 1){
      return head;
    }
    return mergesort(head,i);
  }

  ListNode *mergesort(ListNode* head, int length){
    if(length <= 1){
      return head;
    }
    if(length == 2){
      if (head->val > (head->next)->val){
        swap(head->val, (head->next)->val);
      }
      return head;
    }

    int left = length / 2;
    ListNode* p = head;

    ListNode* mid;
    int i = 1;
    while(i < left){
      p = p->next;
      i++;
    }
    mid = p;

    ListNode* list2 = mergesort(mid->next,length-left);

    mid->next = NULL;
    ListNode* list1 = mergesort(head,left);
    
    ListNode* ans = merge(list1,list2);

    return ans;
    
  }
  ListNode *merge(ListNode* list1,ListNode* list2){
    ListNode* ans;

    if (list1->val <= list2->val){
      ans = list1;
      list1 = list1->next;
    }
    else{
      ans = list2;
      list2 = list2->next;
    }
    ListNode* p=ans;
      
    while((list1 != NULL) && (list2 != NULL)){
      if (list1->val <= list2->val){
        p->next = list1;
        list1 = list1->next;
      }
      else{
        p->next = list2;
        list2 = list2->next;
      }
      p = p->next;
    }
    if (list1 != NULL){
      p->next = list1;
    }
    else{
      p->next = list2;
    }
    return ans;
  }

};
