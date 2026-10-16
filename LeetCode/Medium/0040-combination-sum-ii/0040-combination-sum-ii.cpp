class Solution {
public:
    void func(vector<int>& a, int n, int idx, int target, int sum,
              vector<int>& diary, vector<vector<int>>& res) {

        if (sum == target) {
            res.push_back(diary);
            return;
        }

        if (idx == n || sum > target) return;

        // Take current element
        diary.push_back(a[idx]);
        func(a, n, idx + 1, target, sum + a[idx], diary, res);
        diary.pop_back();

        // Not take current element
        int nextIdx = idx + 1;

        while (nextIdx < n && a[nextIdx] == a[idx]) {
            nextIdx++;
        }

        func(a, n, nextIdx, target, sum, diary, res);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> diary;

        func(candidates, candidates.size(), 0, target, 0, diary, res);

        return res;
    }
};