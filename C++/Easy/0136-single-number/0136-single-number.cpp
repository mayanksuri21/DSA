class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        for(int ele : nums){
            answer = answer ^ ele;
        }
        return answer;
        
    }
};