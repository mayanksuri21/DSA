class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int >f;
        int low = 0 , high = 0 , res = 0 ;
        while(high < s.size()){
            f[s[high]]++;
            int k = high - low + 1; // size of sliding window
            while(f.size() < k){
                f[s[low]]--;
                if(f[s[low]] == 0) f.erase(s[low]);
                low++;
                k = high - low + 1;
            }
            if(f.size() == k){
                int len = high - low + 1;
                res = max(res , len);
            }

            high++;
        }
        return res;
        
    }
};