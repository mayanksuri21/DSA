class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int , vector<int>>> pq;

        for(auto point : points){
            int x = point[0];
            int y = point[1];
            int distance = (x*x + y*y);
          
            pair<int , vector<int>> curr  = {distance , point};

            if(pq.size() < k){
                pq.push(curr);
                continue;
            }
            else if(curr.first < pq.top().first){
                pq.pop();
                pq.push(curr);          
            }
            else{
                continue;
            }
        }
        vector<vector<int>>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;


        
    }
};