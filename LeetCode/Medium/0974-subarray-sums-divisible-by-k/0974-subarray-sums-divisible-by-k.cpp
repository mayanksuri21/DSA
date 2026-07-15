class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int res = 0  , sum = 0;
        unordered_map<int , int> f;
        f[0] = 1;  // 0 % k = 0
        for(int i = 0 ; i < nums.size();i++){
            if(nums.size() == 1) return nums[0] % k == 0 ? 1 : 0;
            sum += nums[i];
            int rem = sum % k;
            if(rem < 0){
                rem += k;
            }
            res += f[rem];
            f[rem]++;
        }  
        return res;   
    }
};