//Remove Duplicates from Sorted List
#include<iostream>
using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == NULL){
      return NULL;
    }
    ListNode* p = head;
    while(p->next != NULL){
      if (p->val == (p->next)->val){
        p->next = (p->next)->next;
      }
      else{
        p = p->next;
      }
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
  head = solution.deleteDuplicates(head);
  //output list
  
  while(head != NULL){
    cout << head->val;
    head = head->next;
  }
  cout << endl;
  return 0;
}
