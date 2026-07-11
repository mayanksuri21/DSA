class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());

        for(int i = 0 ; i< n-2;i++){ 
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int sum = -nums[i];
            int j = i+1 , k = n-1;

            while(j<k){
                int s = nums[j] + nums[k];
                if(sum == s){
                    ans.push_back({nums[i] , nums[j] , nums[k]});
                    j++ , k--;
                    while(j<n && nums[j] == nums[j-1]) j++;
                    while(k>0 && nums[k] == nums[k+1]) k--;

                }
                else if (s < sum) j++;
                else k--;
            }
            
        }

       
        return ans;
    }
};