class Solution {
public:
     int countSubsetSum(vector<int>& arr, int sum) {
        // code here
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
                    dp[i][j] = (dp[i+1][j-arr[i]] + dp[i+1][j]);
                }
            }
        }
        return dp[0][sum];
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(int i: nums){
            totalSum += i;
        }
        if((totalSum + target) %2 != 0 ) return 0;
        if (abs(target) > totalSum)
            return 0;

        int sum = (totalSum + target) / 2;

        return countSubsetSum(nums , sum );
        
        

        
    }
};