class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0 , ans = 0 , i = 0;
        int n = s.size();
        while(i<n){
            if(s[i] == 'L') balance++;
            if(s[i] == 'R') balance--;
            if(balance != 0) i++;
            else{
                ans++;
                i++;
            }
        }

        return ans;

    }
};