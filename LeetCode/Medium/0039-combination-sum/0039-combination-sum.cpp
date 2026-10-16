class Solution {
public:
    void func(vector<int>&a, int n, int idx, int sum,
              vector<int>& diary, vector<vector<int>>& res, int tar) {

        if (idx == n) {
            if (sum == tar) {
                res.push_back(diary);
            }
            return;
        }
        func(a , n , idx+1, sum , diary , res , tar);

        if(a[idx] + sum <= tar){
            diary.push_back(a[idx]);
            sum += a[idx];
            func(a , n , idx,sum , diary , res , tar);
            diary.pop_back();
            sum -= a[idx];
        }

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum = 0, idx = 0;
        vector<int> diary;
        vector<vector<int>> res;
        func(candidates, n, idx, sum, diary, res, target);

        return res;
    }
};