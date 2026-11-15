class Solution {
public:
    int paths(int m , int n , int r , int c ,vector<vector<int>>& grid  , vector<vector<int>>&dp){
        if(r < 0  || r >= m || c < 0 || c >= n || grid[r][c] == 1) return 0;
        if(r == m-1 && c == n-1) return 1;
        if(dp[r][c] != 0) return dp[r][c];

        int c1 = paths( m, n, r+1 , c , grid , dp); 
        int c2 = paths( m, n, r , c+1 , grid , dp); 
        return dp[r][c] = c1 + c2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>>dp(m+1 , vector<int>(n+1 , 0));
        return paths(m , n , 0 , 0 , grid , dp);


        
    }
};