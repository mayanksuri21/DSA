class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while(low < high) {
            int guess = low + (high - low) / 2;

            if(nums[guess] > nums[guess + 1]) {
                high = guess;
            }
            else {
                low = guess + 1;
            }
        }

        return low;
    }
};