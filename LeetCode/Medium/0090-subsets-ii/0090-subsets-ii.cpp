class Solution {
public:
    void subset(vector<int>& nums, int n, int idx,
                vector<int>& diary, vector<vector<int>>& res) {

        if (idx == n) {
                res.push_back(diary);
            
            return;
        };

        diary.push_back(nums[idx]);
        subset(nums, n, idx + 1, diary, res);
        diary.pop_back();
        int i = idx+1;
        while(i < n && nums[i] == nums[i -1]) i++;
        subset(nums, n, i , diary, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int> diary;
        vector<vector<int>> res;

        subset(nums, nums.size(), 0, diary, res);

        return res;
    }
};