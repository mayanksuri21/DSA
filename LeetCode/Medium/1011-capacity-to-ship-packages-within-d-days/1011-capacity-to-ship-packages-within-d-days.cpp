class Solution {
public:

    int daysTaken(vector<int>& weights , int guess){
        int countDays = 0 , sum = 0;
        for(int i = 0 ; i < weights.size();i++){
            if(sum + weights[i] <= guess){
                sum += weights[i];
            } else{
                countDays++;
                sum = weights[i];
            }

        }
        return countDays += 1;


    }
    int shipWithinDays(vector<int>& weights, int days) {
        int high = 0 ; 
        for(int i : weights){
            high += i;
        }
        int low = *max_element(weights.begin(), weights.end()) , res = -1;
        while(low <= high){
            int guess = (low + high)/2;
            if(daysTaken(weights , guess) <= days){
                res = guess ;
                high = guess - 1;

            }else{
                low = guess + 1;
            }
        }

        return res;
        
    }
};