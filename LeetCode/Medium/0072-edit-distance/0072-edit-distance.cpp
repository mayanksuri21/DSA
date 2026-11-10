
class Solution {
public:
    // int fun(string s1, string s2, int i, int j , vector<vector<int>>&dp) {

    //     if(i == s1.length()) return s2.length() - j;
    //     if(j == s2.length()) return s1.length() - i;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(s1[i] == s2[j]) {
    //         return dp[i][j]  = fun(s1, s2, i+1, j+1 , dp);
    //     }
    //     else {
    //         int insert = 1 + fun(s1, s2, i, j+1 , dp);
    //         int del = 1 + fun(s1, s2, i+1, j , dp);
    //         int replace = 1 + fun(s1, s2, i+1, j+1 , dp);

    //         return dp[i][j] = min({insert, del, replace});
    //     }
    // }

    int tab(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int j = 0; j <= m; j++) {
            dp[n][j] = m - j;
        }
        for (int i = 0; i <= n; i++) {
            dp[i][m] = n - i;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j>= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    int insert = 1 + dp[i][j + 1];
                    int del = 1 + dp[i + 1][j];
                    int replace = 1 + dp[i + 1][j + 1];

                    dp[i][j] = min({insert, del, replace});
                }
            }
        }

        return dp[0][0];
    }

    int minDistance(string word1, string word2) { 
        return tab(word1, word2); 
    }
        
};
