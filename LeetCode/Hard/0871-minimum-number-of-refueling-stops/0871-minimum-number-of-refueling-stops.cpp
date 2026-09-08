class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        priority_queue<int> pq;

        int currFuel = startFuel;
        int currPos = 0;
        int stops = 0;

        for (auto station : stations) {

            int pos = station[0];
            int fuel = station[1];

            int distance = pos - currPos;

            // If we cannot reach this station,
            // use fuels of previous stations
            while (currFuel < distance) {

                if (pq.empty()) {
                    return -1;
                }

                currFuel += pq.top();
                pq.pop();
                stops++;
            }

            // Reach the station
            currFuel -= distance;
            currPos = pos;

            // Save this station's fuel for future
            pq.push(fuel);
        }

        // Now reach the destination
        int distance = target - currPos;

        while (currFuel < distance) {

            if (pq.empty()) {
                return -1;
            }

            currFuel += pq.top();
            pq.pop();
            stops++;
        }

        return stops;
    }
};