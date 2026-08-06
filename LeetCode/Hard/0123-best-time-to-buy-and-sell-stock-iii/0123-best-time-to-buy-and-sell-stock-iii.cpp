class Solution {
public:
    vector<vector<int>> dp;

    int func(vector<int>& a, int n, int i, int k) {
        if (i == n || k == 0 )
            return 0;

        if (dp[i][k] != -1)
            return dp[i][k];

        if (k % 2 == 0) { // Buy state
            int buy = func(a, n, i + 1, k - 1) - a[i];
            int skip = func(a, n, i + 1, k);

            return dp[i][k] = max(buy, skip);
        }
        else { // Sell state
            int sell = func(a, n, i + 1, k-1) + a[i];
            int skip = func(a, n, i + 1, k);

            return dp[i][k] = max(sell, skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 4;

        dp.assign(n+1, vector<int>(k+1, -1));

        return func(prices, n, 0, k);
        
    }
};