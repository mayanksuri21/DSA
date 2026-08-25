class Solution {
public:
    int func(vector<int>& citations, int guess) {
        int count = 0;

        for(int i = 0; i < citations.size(); i++) {
            if(citations[i] >= guess)
                count++;
        }

        return count;
    }

    int hIndex(vector<int>& citations) {
        int low = 0;
        int n = citations.size();
        int high = n;
        int res = 0;

        while(low <= high) {
            int guess = low + (high - low) / 2;
            int count_papers = func(citations, guess);

            if(count_papers >= guess) {
                res = guess;
                low = guess + 1;
            }
            else {
                high = guess - 1;
            }
        }

        return res;
    }
};