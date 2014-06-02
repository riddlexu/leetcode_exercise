#include<iostream>
using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
 public:
  ListNode *swapPairs(ListNode *head) {
    if (head == NULL){
      return NULL;
    }
    else if (head->next == NULL){
      return head;
    }
    ListNode* a = head;
    ListNode* b = head->next;
    ListNode* before = NULL;
    head = b;
    while(b != NULL){
      a->next = b->next;
      b->next = a;
      if(before != NULL){
        before->next = b;
      }
      if (a->next == NULL){
        return head;
      }
      before = a;
      a = a->next;
      b = a->next;

    }
    return head;
  }
};


int main()
{
  int n;
  cin >> n;
  ListNode* head;
  ListNode* p = (ListNode*)malloc(sizeof(ListNode)*n);
  //input list
  for (int i = 0; i < n - 1; i++){
    head = &p[i];
    cin >> head->val;
    head->next = &p[i+1];
  }
  cin >> (&p[n-1])->val;

  head = &p[0];
  Solution solution;
  head = solution.swapPairs(head);
  //output list
  
  for (int i = 0; i < n; i++){
    cout << head->val;
    head = head->next;
  }
  cout << endl;
  return 0;
}
