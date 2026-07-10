
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int missing , repeating;
        for(int val = 1 ; val <= n; val++){
            int count = 0;
            for(int i = 0 ; i < n ; i++){
                if(nums[i] == val){
                    count++;
                };
            };
            if(count == 0) missing = val;
            else if(count > 1) repeating = val;
        };

        return {repeating , missing};


    }; 
}; 