class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size() , res = 0 , sum = 0 ;
        unordered_map<int, int> f;
        f[0] = 1;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            int ques = sum - goal;
            int freq = f[ques];
            res += freq;
            f[sum]++;
        }
        return res;
    }
};