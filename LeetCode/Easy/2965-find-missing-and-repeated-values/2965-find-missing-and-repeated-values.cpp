class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        int n = grid[0].size();
        vector<int> freq(n*n+1,0);
        for(int i = 0 ; i<n;i++){
            for(int j = 0 ; j < n;j++){
                int x = grid[i][j];
                freq[x]++;
            }
        }
        int a , b;
        for(int i = 1; i <= n*n;i++){
            if(freq[i] == 2) a = i;
            if(freq[i] == 0) b = i;
        }
        
        ans.push_back(a);
        ans.push_back(b);

        return ans;

        
    }
};