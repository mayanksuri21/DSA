class Solution {
public:
    int func(vector<int>& cost , int n , int idx , vector<int>&dp){
        if(idx == 1) {
            dp[1] = 0;
        }

        else{
            dp[1] = cost[0];
        }

        for(int i = 2; i <= n;i++){
            int jmp1 = dp[i-1] + cost[i-1];
            int jmp2 = dp[i-2] + cost[i-2];
            dp[i] = min(jmp1 , jmp2);
        }

        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 0) return 0;
        vector<int>dp(n+1);
        dp[0] = 0;
        int c1 = func(cost , n , 0 , dp);
        int c2 = func(cost , n ,1 , dp);
        return min(c1 , c2);
        
    }
};