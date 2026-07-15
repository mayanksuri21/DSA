class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int resSum;
        int maxDiff = INT_MAX;
        for(int i = 0 ; i< n-2;i++){
            int j = i+1 , k= n-1;
            while(j<k){
                int sum = nums[i] + nums[j] +nums[k];  
                int diff = abs(sum - target);
                if(diff < maxDiff){
                    maxDiff = diff;
                    resSum = sum;
                }
                if(sum < target) j++;       
                else if(sum > target) k--; 
                else{
                    return sum;
                }      
            }
        }
        return resSum;
        
    }
};