class Solution {
public:
    void func(string digits, int n, int idx, unordered_map<char, string> f,
              string& diary, vector<string>& res) {
        if (idx == n) {
            res.push_back(diary);
            return;
        }

        string choices = f[digits[idx]];
        for (int j = 0; j < choices.size(); j++) {
            diary.push_back(choices[j]);
            func(digits, n, idx + 1,f, diary, res);
            diary.pop_back();
        }

        return;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> f;
        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";

        int n = digits.size();
        int idx = 0;
        string diary = "";
        vector<string> res;

        func(digits, n, idx, f, diary, res);
        return res;
    }
};