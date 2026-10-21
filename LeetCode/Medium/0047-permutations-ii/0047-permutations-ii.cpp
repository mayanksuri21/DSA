class Solution {
public:
     void func(vector<int>& nums , int n ,int idx,  vector<vector<int>> &res){
        if(idx == n){
            res.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for(int i = idx ; i< n; i++){
           
            if(s.find(nums[i]) != s.end()){
                continue;
            }
            s.insert(nums[i]);
            swap(nums[i],nums[idx]);
            func(nums , n , idx+1 , res);
            swap(nums[i],nums[idx]);
            
           
            
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        func(nums , nums.size(),0, res);
        return res;
        
    }
};