class Solution {
public:
    string build(string str) {
        string res;

        for (char ch : str) {
            if (ch != '#') {
                res.push_back(ch);
            } else if (!res.empty()) {
                res.pop_back();
            }
        }

        return res;
    }
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
        // int i = 0  ;

        // while(i < s.size()){
        //     if( i == 0 && s[i] == '#'){
        //         s.erase(i,1);
        //         i = 0 ;
        //     }
        //     else if( i>0 && s[i] == '#'){
        //         s.erase(i-1, 2);
        //         i--;
        //     }
        //     else{
        //         i++;
        //     }
        // }

        // int j = 0;

        // while(j < t.size()){
        //     if( j == 0 && t[j] == '#'){
        //         t.erase(j,1);
        //         j = 0 ;
        //     }
        //     else if( j>0 && t[j] == '#'){
        //         t.erase(j-1, 2);
        //         j--;
        //     } else j++;
        // }

        // return s == t;
    }
};