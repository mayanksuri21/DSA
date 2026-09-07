class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
                
        sort(courses.begin(),courses.end(),[](vector<int>&a , vector<int>&b){
            return a[1] < b[1];
        });

        priority_queue<int> pq;
        int count = 0 , totalDuration = 0;

        for(auto course : courses){
            int duration = course[0];
            int deadline = course[1];

            pq.push(duration);
            totalDuration += duration;

            if(totalDuration > deadline){
                totalDuration -= pq.top();
                pq.pop();
            }
            else{
                count++;

            }


        }
         

        return count;
        
    }
};