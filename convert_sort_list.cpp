//https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int length = 0;
        ListNode* p = head;
        while(p != NULL){
            p = p->next;
            length++;
        }
        if (length == 0){
            return NULL;
        }
        if (length == 1){
            TreeNode* tree = new TreeNode(head->val);
            return tree;
        }
        if (length == 2){
            TreeNode* tree1 = new TreeNode(head->val);
            TreeNode* tree2 = new TreeNode((head->next)->val);
        }
        
        int mid = length / 2;
        p = head;
        int i = 0;
        while(i < mid - 1){
            i++;
            p = p->next;
        }
        TreeNode* root = new TreeNode((p->next)->val);
        TreeNode* right = sortedListToBST((p->next)->next);
        p->next = NULL;
        TreeNode* left = sortedListToBST(head);
        root->left = left;
        root->right = right;
        return root;
        
    }
};
