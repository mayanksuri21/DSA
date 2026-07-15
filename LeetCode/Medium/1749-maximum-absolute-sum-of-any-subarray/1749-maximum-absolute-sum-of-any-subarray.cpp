class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minsum = nums[0];
        int maxsum = nums[0];
        int res = abs(nums[0]);
        for(int i = 1 ; i < nums.size();i++){
            int v1 = nums[i];
            int v2 = minsum + nums[i];
            int v3 = maxsum + nums[i];
            minsum = min(v1 , min(v2,v3));
            maxsum = max(v1 , max(v2,v3));
            res = max( res , max(abs(minsum) , abs(maxsum)));
            
        }

        return  res;

        
    }
};