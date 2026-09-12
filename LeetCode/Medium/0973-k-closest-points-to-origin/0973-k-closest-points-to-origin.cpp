class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int , vector<int>>,vector<pair<int , vector<int>>>,greater<pair<int , vector<int>>>> pq;

        for(auto point : points){
            int x = point[0];
            int y = point[1];
            int distance = (x*x + y*y);

            pq.push(make_pair(distance , point));
          
        }

        vector<vector<int>>res;
        for(int i = 0 ; i < k;i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        

        return res;


        
    }
};