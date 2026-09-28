class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        unordered_map<int , int> m;
        for(int el : nums1){
            m[el]++;
        }
        for(int el : nums2){
            if(m.find(el) != m.end()){
                res.push_back(el);
                m[el]--;
                if(m[el] == 0) m.erase(el);
            }
        }

        return res;
        
        
    }
};