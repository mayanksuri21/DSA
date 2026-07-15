class Solution {
public:
    bool isValid(string s) {
        stack<char>ans;
        for(int i = 0 ; i<s.size();i++){
            char ch = s[i];
            if(ch == '('|| ch == '['|| ch == '{'){
                ans.push(ch);
            }
            else{
                if(ans.empty()) return false;
                else{
                    char top = ans.top();
                    if(top == '('&& ch == ')'|| top == '['&& ch == ']'|| top == '{'&& ch == '}'){
                        ans.pop();
                    }
                    else{
                        return false;
                    }

                }
            }
        }
        return (ans.empty()) ? true : false;
        
        

        
    }
};