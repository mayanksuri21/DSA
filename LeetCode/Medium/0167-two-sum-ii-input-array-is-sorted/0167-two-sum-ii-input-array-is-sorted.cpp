class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i = 0 ; i<numbers.size();i++){
            int first = numbers[i];
            int sec = target - numbers[i];

            if(m.find(sec) != m.end()){
                ans.push_back(m[sec]+1);
                ans.push_back(i+1);
            }
            m[first] = i;
        }
        return ans;
        
    }
};