//https://oj.leetcode.com/problems/rotate-list/
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
    ListNode *rotateRight(ListNode *head, int k) {
        if ((k == 0) || (head == NULL)){
            return head;
        }
        int length = 1;
        ListNode* p = head;
        while(p->next != NULL){
            length++;
            p = p->next;
        }
        if (length == 1){
            return head;
        }
        p->next = head;
        int step = length - k % length;
        for(int i = 0; i < step; i++){
            p = p->next;
        }
        ListNode* newhead = p->next;
        p->next = NULL;
        return newhead;
    }
};
