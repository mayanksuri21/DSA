class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double , vector<int>>> pq;

        for(auto point : points){
            int x = point[0];
            int y = point[1];
            double distance = sqrt(x*x + y*y);
          
            pair<double , vector<int>> curr  = {distance , point};

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