class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<int> sf(26,0);
        vector<int> pf(26,0);
        vector<int> ans;

        for(char ch : p){
            pf[ch - 'a']++;
        }

        int low = 0 , high = 0;

        while(high < n){
            sf[s[high] - 'a']++;
            int len = high - low + 1;
            if(len > p.size()){
                sf[s[low]-'a']--;
                low++;
            }
            if(sf == pf){
                ans.push_back(low);
            }
            high++;
        }

        return ans;

        
    }
};