class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0]; // bestending
        int maxsum = nums[0];

        for(int i = 1; i< nums.size();i++){
            int sum1 = nums[i];
            int sum2 = sum + nums[i];
            sum = max(sum1 , sum2);
            maxsum= max(maxsum , sum);
        }

        return maxsum;
    }
};