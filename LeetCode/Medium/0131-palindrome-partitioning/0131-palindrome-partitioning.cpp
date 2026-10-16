class Solution {
public:

    bool isPalindrome(string s){
        string s2 = s;
        reverse(s2.begin(),s2.end());

        return s == s2;
    };

    void getParts(string s , vector<string>&partitions , vector<vector<string>>&res){

        if(s.size() == 0){
            res.push_back(partitions);
            return;
        }

        for(int i = 0 ; i < s.size();i++){
            string part = s.substr(0 , i+1);
            if(isPalindrome(part)){
                partitions.push_back(part);
                getParts(s.substr(i+1) , partitions , res);
                partitions.pop_back();
            }

        }



    }
    vector<vector<string>> partition(string s) {
        vector<string>partitions;
        vector<vector<string>> res;

        getParts(s , partitions , res);
        return res;

        
    }
};