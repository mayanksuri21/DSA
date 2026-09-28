class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        unordered_set<int> s;
        for(int el : nums1){
            s.insert(el);
        }
        for(int el : nums2){
            if(s.find(el) != s.end()){
                res.push_back(el);
                s.erase(el);
            }
        }

        return res;
        
    }
};