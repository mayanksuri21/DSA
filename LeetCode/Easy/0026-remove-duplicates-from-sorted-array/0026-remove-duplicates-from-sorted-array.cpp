class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique = 1;
        int i = 0 , j = 1;
        while(j<nums.size()){
            if(nums[j] == nums[j-1]){
                j++;
            }
            else{
                nums[i+1] = nums[j];
                unique += 1;
                i++ , j++;
            }
        }

        return unique;
        
    }
};