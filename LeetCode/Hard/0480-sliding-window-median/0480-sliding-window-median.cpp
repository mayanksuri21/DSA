class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        priority_queue<int> left_max;
        priority_queue<int, vector<int>, greater<int>> right_min;

        unordered_map<int, int> deleted;

        int leftSize = 0;
        int rightSize = 0;

        // Add number
        auto addNum = [&](int num) {

            if (left_max.empty() || num <= left_max.top()) {
                left_max.push(num);
                leftSize++;
            }
            else {
                right_min.push(num);
                rightSize++;
            }

            // Maintain heaps
            if (leftSize > rightSize + 1) {
                right_min.push(left_max.top());
                left_max.pop();

                leftSize--;
                rightSize++;
            }
            else if (rightSize > leftSize) {
                left_max.push(right_min.top());
                right_min.pop();

                rightSize--;
                leftSize++;
            }
        };

        // Remove number
        auto removeNum = [&](int num) {

            deleted[num]++;

            if (num <= left_max.top()) {
                leftSize--;
            }
            else {
                rightSize--;
            }

            // Remove invalid top elements from left
            while (!left_max.empty() &&
                   deleted[left_max.top()] > 0) {

                deleted[left_max.top()]--;
                left_max.pop();
            }

            // Remove invalid top elements from right
            while (!right_min.empty() &&
                   deleted[right_min.top()] > 0) {

                deleted[right_min.top()]--;
                right_min.pop();
            }

            // Maintain heaps
            if (leftSize > rightSize + 1) {

                right_min.push(left_max.top());
                left_max.pop();

                leftSize--;
                rightSize++;
            }
            else if (rightSize > leftSize) {

                left_max.push(right_min.top());
                right_min.pop();

                rightSize--;
                leftSize++;
            }
        };

        // Find median
        auto findMedian = [&]() -> double {

            while (!left_max.empty() &&
                   deleted[left_max.top()] > 0) {

                deleted[left_max.top()]--;
                left_max.pop();
            }

            while (!right_min.empty() &&
                   deleted[right_min.top()] > 0) {

                deleted[right_min.top()]--;
                right_min.pop();
            }

            if (leftSize == rightSize) {
                return ((double)left_max.top() +
                        (double)right_min.top()) / 2.0;
            }

            return (double)left_max.top();
        };

        vector<double> ans;

        // First window
        for (int i = 0; i < k; i++) {
            addNum(nums[i]);
        }

        ans.push_back(findMedian());

        // Sliding window
        for (int i = k; i < nums.size(); i++) {

            // Remove old element
            removeNum(nums[i - k]);

            // Add new element
            addNum(nums[i]);

            // Find median
            ans.push_back(findMedian());
        }

        return ans;
    }
};