class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        //    int zero = 0 , one = 0 ,two = 0;
        //    for(int i = 0 ;i<n;i++){
        //     if(nums[i] == 0) zero++;
        //     else if(nums[i] == 1) one++;
        //     else two++;
        //    }
        //    int idx = 0;
        //    for(int i = 0 ;i<zero;i++){
        //     nums[idx++] = 0;
        //    }
        //    for(int i = 0 ;i<one;i++){
        //     nums[idx++] = 1;
        //    }
        //    for(int i = 0 ;i<two;i++){
        //     nums[idx++] = 2;
        //    }

        // with two pointer
        int low = 0, mid = 0, high = n - 1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid] , nums[low]);
                low++ , mid++;

            }
            else if ( nums[mid] == 1){
                mid++;

            }
            else{ //  nums[mid] == 2
                swap(nums[mid] , nums[high]);
                high--;


            }
        }
        return ;
    }
};