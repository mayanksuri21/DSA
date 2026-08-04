class Solution {
public:
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n+1 , vector<int>(sum + 1 , -1));
        for(int j = 0 ; j <= sum; j++){
            dp[n][j] = 0;
        } 
        dp[n][0] = 1;
        
        for(int i = n-1 ; i >= 0; i--){
            for(int j = 0 ; j <= sum ;j++){
                if(arr[i] > j) dp[i][j] = dp[i+1][j];
                else{
                    dp[i][j] = (dp[i+1][j-arr[i]] || dp[i+1][j]);
                }
            }
        }
        return dp[0][sum];
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i : nums){
            totalSum += i;
        }
        if(totalSum % 2 != 0) return false;
        return isSubsetSum(nums , totalSum/2 );

        
        
    }
};