class Solution {
public:
    int coinCount(vector<int>& coins, int n, int i, int amount,
                  vector<vector<int>>& dp) {

        if (amount == 0) return 0;

        if (i == n) return 1e9;

        if (dp[i][amount] != -1) return dp[i][amount];

        // Skip current coin
        int skip = coinCount(coins, n, i + 1, amount, dp);

        // Take current coin
        int take = 1e9;

        if (coins[i] <= amount) {
            take = 1 + coinCount(coins, n, i, amount - coins[i], dp);
        }

        return dp[i][amount] = min(skip, take);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = coinCount(coins, n, 0, amount, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};