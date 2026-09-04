class Solution {
public:
    struct cmp {
        bool operator()(pair<int,int> a , pair<int ,int> b){
            if(a.first != b.first){
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        unordered_map<int , int> f;
        for(int i = 0 ; i < mat.size();i++){
            int cnt1 = 0;
            for(int j = 0 ; j < mat[0].size();j++){
                if(mat[i][j] == 1) cnt1++;
                
            }
            f[i] = cnt1;
        }

        priority_queue<pair<int,int> , vector<pair<int,int>> , cmp>pq;

        for(auto i : f){
            int row = i.first;
            int sold = i.second;
            pair<int,int> curr = {sold , row};

            if(pq.size() < k) {
                pq.push(curr);
            }
            else if(curr.first < pq.top().first || (curr.first == pq.top().first && curr.second < pq.top().second)){
                pq.pop();
                pq.push(curr);
            }
        }

        vector<int>res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;

        
    }
};