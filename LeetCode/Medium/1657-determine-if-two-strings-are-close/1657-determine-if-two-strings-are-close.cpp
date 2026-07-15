class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        if(n!= m){
            return false;
        }

        // Array from index 0-25 initialized with 0 at all index
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(int i = 0 ; i < n ; i++){
            char ch1 = word1[i];
            char ch2 = word2[i];

            freq1[ch1-'a']++;
            freq2[ch2-'a']++;

        }
        
        // check if a particular chr is present in first string
        // but not in second string or vice versa

        for(int i = 0 ; i < 26;i++){
            
            if((freq1[i]>0 && freq2[i]==0) || (freq1[i]==0 && freq2[i] > 0)){
                return false;
            }
        }

        sort(freq1.begin() , freq1.end());
        sort(freq2.begin() , freq2.end());

        if(freq1 == freq2) return true;
        else return false;
    }
};