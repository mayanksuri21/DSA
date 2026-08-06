class Solution {
public:
  
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        vector<vector<int>>dp(n+1 , vector<int>(k+1 , -1));
        for(int i = 0 ; i <= n;i++){
            dp[i][0] = 0;
        }
        for (int j = 0; j <= 2; j++) {
            dp[n][j] = 0;
        }       

        for(int i = n-1 ; i >= 0 ; i--){
            //buy k = 2
                dp[i][2] = max(dp[i+1][1] - prices[i] , dp[i+1][2]);
        
            // k ==1 sell
                dp[i][1] = max(dp[i+1][2] + prices[i] , dp[i+1][1]);

            
        }
       

        
        return dp[0][2];
    }
        
    
};