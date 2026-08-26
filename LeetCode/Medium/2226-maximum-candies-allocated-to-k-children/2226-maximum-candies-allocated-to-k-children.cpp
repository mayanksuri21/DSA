class Solution {
public:

    long long Cancandies(vector<int>& candies, int guess){
        long long count = 0;
        for(int i = 0 ; i < candies.size();i++){
        
            count += candies[i] / guess;

        }
        return count;

    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1 , high = *max_element(begin(candies) , end(candies)) , res = 0;

        while(low <= high){
            int guess = (low + high) / 2;

            if(Cancandies(candies , guess) >= k){
                res = guess;
                low = guess  + 1;
            }
            else{
                high = guess - 1;
            }
        }

        return res;
        
    }
};