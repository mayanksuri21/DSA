class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<int , vector<int> , greater<int>> pq;
        for(int i : arr){
            int a = i;
            if(pq.size() < k){
                pq.push(a);
                continue;
            }
            int b = pq.top();
            if((abs(a-x) < abs(b-x)) || (abs(a-x) == abs(b-x) && a < b)){
                pq.pop();
                pq.push(a);

            }
            else{
                continue;
            }
        }

        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }


        return res;
        
    }
};