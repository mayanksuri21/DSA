class Solution {
public:
    int first(vector<int>& nums, int target){
        int low = 0 , high = nums.size()-1, res = -1;
        while(low <= high){
            int guess = (low + high)/2;
            if(nums[guess] < target) low = guess + 1;
            else if(nums[guess] > target) high = guess - 1;

            else{
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }
    int last(vector<int>& nums, int target){
        int low = 0 , high = nums.size()-1, res = -1;
        while(low <= high){
            int guess = (low + high)/2;
            if(nums[guess] < target) low = guess + 1;
            else if(nums[guess] > target) high = guess - 1;

            else{
                res = guess;
                low = guess + 1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res;
        res.push_back(first(nums,target));
        res.push_back(last(nums,target));

        return res;
        
    }
};