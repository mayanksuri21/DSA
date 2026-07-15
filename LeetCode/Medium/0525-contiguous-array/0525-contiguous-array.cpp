class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int currsum = 0 , res = 0 ;
        unordered_map<int,int>f;
        f[0] = -1;
        for(int i = 0 ; i < nums.size();i++){
            if(nums[i] == 0) currsum += -1;
            else currsum += 1;

            if(f.find(currsum) == f.end()){
                f[currsum] = i;
            }
            else{
                int len = i-f[currsum];
                res = max(res, len);
            }
        }

       

        return res;
        
    }
};