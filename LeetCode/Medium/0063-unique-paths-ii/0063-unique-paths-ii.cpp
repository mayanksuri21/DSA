class Solution {
public:
    // int paths(int m , int n , int r , int c ,vector<vector<int>>& grid  ,
    // vector<vector<int>>&dp){
    //     if(r < 0  || r >= m || c < 0 || c >= n || grid[r][c] == 1) return 0;
    //     if(r == m-1 && c == n-1) return 1;
    //     if(dp[r][c] != 0) return dp[r][c];

    //     int c1 = paths( m, n, r+1 , c , grid , dp);
    //     int c2 = paths( m, n, r , c+1 , grid , dp);
    //     return dp[r][c] = c1 + c2;
    // }

    int tabulation(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        if (grid[m - 1][n - 1] == 1)
            return 0;
        dp[m - 1][n - 1] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)
                    continue;
                else if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                } else {

                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                }
            }
        }
        return dp[0][0];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // int m = grid.size() , n = grid[0].size();
        // vector<vector<int>>dp(m+1 , vector<int>(n+1 , 0));
        return tabulation(grid);
    }
};