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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* tail = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return tail;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head , *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next ;
        slow->next = NULL;
        ListNode* tail = reverseList(temp);
        
        while(tail){
            ListNode* next1 = head->next;
            ListNode* next2 = tail->next;
            head->next = tail;
            tail->next = next1;

            head = next1;
            tail = next2;

        }
        return;

    }
};