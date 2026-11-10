class Solution {
public:
    int func(string &s  , int i , int j , vector<vector<int>>&dp){

        if(j < i) return 0;
        if( i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]){
            return  dp[i][j] = 2 + func(s , i+1 , j-1 , dp);
        }
        int c1 = func(s , i+1 , j , dp);
        int c2 = func(s , i , j-1 , dp);
        return dp[i][j] = max(c1 , c2);
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(s.size() , vector<int>(s.size() , -1));
        return func(s , 0 , s.length() - 1 , dp);
        
        
    }
};