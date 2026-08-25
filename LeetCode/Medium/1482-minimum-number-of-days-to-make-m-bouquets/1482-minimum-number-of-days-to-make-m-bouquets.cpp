class Solution {
public:

    int canMakebouq(vector<int>& bloomDay, int guess, int k){
        int consecutive_count = 0;
        int bouquets = 0;

        for(int i = 0 ; i < bloomDay.size();i++){
            if(bloomDay[i] <= guess){
                consecutive_count++;
            }else{
                consecutive_count = 0;
            }

            if(consecutive_count == k){
                bouquets++;
                consecutive_count = 0;
            }
        }
        return bouquets;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int start_day = 1 , end_day = *max_element(begin(bloomDay) , end(bloomDay));
        int res = -1;

        while(start_day <= end_day){
            int guess = (start_day + end_day)/2;
            if(canMakebouq(bloomDay , guess , k) >= m){
                res = guess;
                end_day = guess -1;
            }
            else{
                start_day = guess + 1;
            }
        }

        return res;
        
    }
};