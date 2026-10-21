class Solution {
public:
    unordered_set<int> st;
    void func(vector<int>& nums , int n , vector<int>&diary , vector<vector<int>> &res){
        if(diary.size() == n){
            res.push_back(diary);
            return;
        }
        for(int i = 0 ; i< n; i++){
            if(st.find(nums[i]) == st.end()){
                diary.push_back(nums[i]);
                st.insert(nums[i]);
                func(nums , n ,diary , res);
                diary.pop_back();
                st.erase(nums[i]);
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> diary;
        vector<vector<int>> res;
        func(nums , nums.size(),  diary , res);
        return res;
        
    }
};