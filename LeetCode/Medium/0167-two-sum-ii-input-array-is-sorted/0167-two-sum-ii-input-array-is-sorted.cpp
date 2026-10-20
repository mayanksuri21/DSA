class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int i = 0;
        int j = numbers.size()-1;
        vector<int>res;

        while(i<j){
            if(numbers[i] + numbers[j]  == target){
                res.insert(res.begin(),{i+1 , j+1});
                break;
            }
            else if(numbers[i] + numbers[j]  < target){
                i++;
            }
            else{
                j--;
            }

        }
        return res;
    }
};