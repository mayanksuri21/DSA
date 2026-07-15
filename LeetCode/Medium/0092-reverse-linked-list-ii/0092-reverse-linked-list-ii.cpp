class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(!head || left == right) return head;

        ListNode* t = head;
        ListNode* before = NULL;

        int pos = 1;

        // Move to left position
        while(pos < left){
            before = t;
            t = t->next;
            pos++;
        }

        // Reverse sublist
        ListNode* curr = t;
        ListNode* prev = NULL;

        int times = right - left + 1;

        while(times-- && curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Connect remaining list
        t->next = curr;

        if(before){
            before->next = prev;
            return head;
        }

        return prev;
    }
};