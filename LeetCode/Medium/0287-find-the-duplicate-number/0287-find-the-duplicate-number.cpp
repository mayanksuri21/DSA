class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0 , fast = 0 ;
        while(true){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
            if(slow == fast){  //  cycl detect and meeting point
                slow =  0 ; 
                while(slow != fast){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return slow; // starting point of the cycle which is the duplicate element
            }
        }
        return -1;
        
    }
};