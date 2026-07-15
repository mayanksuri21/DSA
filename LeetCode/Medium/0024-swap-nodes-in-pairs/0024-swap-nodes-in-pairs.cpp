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
    void reverse(ListNode* head , int times){

        ListNode* curr = head;
        ListNode* prev = NULL;
        while(times--){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return;
        
    }
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        int size = 2;
        ListNode* left = head;
        ListNode* res  = NULL;
        ListNode* prevLeft = NULL;
        ListNode* right;

        while(true){
            right = left;
            for(int i = 0 ;  i < size-1;i++){
                if(right == NULL){
                    break;
                }
                right = right->next;
            }
            if(right){
                ListNode* nextLeft = right->next;
                reverse(left ,size);
                if(prevLeft){
                    prevLeft->next = right;
                }
                prevLeft = left;
                left = nextLeft;
                if(res == NULL) res = right;
            }
            else{
                if(prevLeft){
                    prevLeft->next = left;    
                }
               
                break;
            }
            
        }

        return res;
        
    }
};