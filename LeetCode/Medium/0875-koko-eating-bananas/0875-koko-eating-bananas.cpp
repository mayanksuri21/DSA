class Solution {
public:
    long long totalHour(vector<int>& piles, int n, int speed) {
        long long hrs = 0;

        for (int i = 0; i < n; i++) {
            hrs += (piles[i] + speed - 1) / speed;
        }

        return hrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int res = high;

        while (low <= high) {
            int guess = low + (high - low) / 2;

            long long hour = totalHour(piles, piles.size(), guess);

            if (hour > h) {
                low = guess + 1;
            } else {
                res = guess;
                high = guess - 1;
            }
        }

        return res;
    }
};