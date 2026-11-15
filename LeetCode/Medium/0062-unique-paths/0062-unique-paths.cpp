class Solution {
public:
    int totalPaths(int m , int n , int r , int c ,  vector<vector<int>>&dp){
        if(r == m-1 && c ==n-1){
            return 1;
        }
        if(dp[r][c] != 0) return dp[r][c];
       
        if(r < 0 || r >= m || c < 0 || c >= n)  return 0;

        int c1 = totalPaths(m , n , r , c+1 , dp);
        int c2 = totalPaths(m , n, r+1 , c , dp);
        return  dp[r][c] = c1 + c2;


    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1 , 0));
        return totalPaths(m,n , 0 , 0 , dp);
    }
};