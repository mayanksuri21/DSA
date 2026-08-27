class Solution {
public:

    int possibleSubarrays(vector<int>& nums , int guess){
        int countSub = 0 , tempSum = 0 ;
        for(int i = 0 ; i < nums.size();i++){
            if(tempSum + nums[i] <= guess){
                tempSum += nums[i];
            } else{
                countSub++;
                tempSum = nums[i];
            }
             
        }
        countSub++;
        return countSub;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end()) , high = 0 , res = -1;
        for(int i : nums){
            high += i;
        }

        while(low <= high){
            int guess = (low + high )/2;
            if(possibleSubarrays(nums , guess) <= k){
                res = guess;
                high = guess - 1;
            }
            else{
                low = guess + 1;
            }
        }

        return res;
        
    }
};