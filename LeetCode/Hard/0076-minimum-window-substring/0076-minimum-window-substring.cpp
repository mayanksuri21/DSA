class Solution {
public:
    bool eqFreq(int need[256] , int have[256]){
        for(int i = 0 ; i < 256;i++){
            if(have[i] < need[i]) return false;
        }

        return true;
    }
    string minWindow(string s, string t) {
        int need[256]  = {0}; // for t
        int have[256]  = {0}; // for s
        for(int i = 0 ; i < t.size();i++){
            need[t[i]]++;
        }
        int low = 0 , high = 0 , res = INT_MAX , start;
        for(high = 0 ; high < s.size();high++){
            have[s[high]]++;
            while(eqFreq(need, have)){
                int len = high - low + 1;
                if(res > len) {
                    res = len;
                    start = low;
                }
                have[s[low]]--;
                low++;
            }

        }
        return res == INT_MAX ? "" : s.substr(start , res);
        

        
    }
};