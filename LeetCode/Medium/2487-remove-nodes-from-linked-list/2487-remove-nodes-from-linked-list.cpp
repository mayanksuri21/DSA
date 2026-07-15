/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseNodes(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* tail = reverseNodes(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;

    }

    ListNode* removeNodes(ListNode* head) {
        head = reverseNodes(head);
        ListNode* curr = head;
        int maxval = head->val;
        while(curr && curr->next){
            if(curr->next->val < maxval){
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
                maxval = curr->val;
            }
        }
        return reverseNodes(head);
        
    }
};