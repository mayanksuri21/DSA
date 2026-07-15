class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0 , high = 0 , res = INT_MAX;
        int sum = 0 ;
        for(high = 0; high < nums.size();high++){
            sum += nums[high];
            while(sum >= target){ // write condition
                int len = high - low +1;
                res = min(res , len);
                sum -= nums[low];
                low++;
            }


        }
        return res == INT_MAX ? 0 : res;


      
    }
};