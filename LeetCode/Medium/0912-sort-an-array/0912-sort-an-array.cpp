class Solution {
public:
    void heapify(int i , vector<int>&nums , int n){
        if(i >= n) return;

        int l = 2*i + 1;
        int r = 2*i + 2;
        int maxI = i;

        if(l < n && nums[l] > nums[maxI]){
            maxI = l;
        }
        if(r < n && nums[r] > nums[maxI]){
            maxI = r;
        }

        if(maxI != i){
            swap(nums[maxI] , nums[i]);
            heapify(maxI , nums , n);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {

        vector<int>res;
        int n = nums.size();
        for(int i = n/2 -1 ; i>=0;i-- ){
            heapify(i , nums, n);
        }

        for(int i = n-1;i>=0;i--){
            res.push_back(nums[0]);
            swap(nums[0],nums[i]);
            heapify(0,nums,i);
        }

        reverse(res.begin(),res.end());
       

        return res;


    }
};