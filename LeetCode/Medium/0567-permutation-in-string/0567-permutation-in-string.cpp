class Solution {
public:
   
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if(n > m) return false;
        vector<int> s1Freq(26,0);
        vector<int> s2Freq(26,0);
        for(char ch : s1){
            s1Freq[ch - 'a']++;

        }

        int low = 0 , high = 0;
        while(high < m){
            s2Freq[s2[high] - 'a']++;

            int len = high - low + 1;
            if(len > n){
                s2Freq[s2[low] - 'a']--;
                low++;
            }
            if(s1Freq == s2Freq) return true;

            high++;

        }
        return false;
    }
};