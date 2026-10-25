
class Solution {
public:
    int fun(vector<int>& nums, int n, int i, int free,
            int house1robbed, vector<vector<vector<int>>>& dp) {

        if (i == n) return 0;

        if (dp[i][free][house1robbed] != -1)
            return dp[i][free][house1robbed];

        // Previous house was robbed, so skip current house
        if (free == 0) {
            return dp[i][free][house1robbed] =
                fun(nums, n, i + 1, 1, house1robbed, dp);
        }

        // Last house cannot be robbed if first house was robbed
        if (i == n - 1 && house1robbed == 1) {
            return dp[i][free][house1robbed] =
                fun(nums, n, i + 1, 1, house1robbed, dp);
        }

        // Choice 1: Rob current house
        int robbedFirst = house1robbed;
        if (i == 0) robbedFirst = 1;

        int c1 = nums[i] +
            fun(nums, n, i + 1, 0, robbedFirst, dp);

        // Choice 2: Skip current house
        int c2 = fun(nums, n, i + 1, 1, house1robbed, dp);

        return dp[i][free][house1robbed] = max(c1, c2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(2, -1))
        );

        return fun(nums, n, 0, 1, 0, dp);
    }
};
