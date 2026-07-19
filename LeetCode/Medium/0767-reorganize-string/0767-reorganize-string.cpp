class Solution {
public:
    struct cmp{
        bool operator()(pair<int ,char> a , pair<int , char > b){
            if(a.first != b.first)
            return a.first < b.first;

            return a.second < b.second;
        }
    };
    string reorganizeString(string s) {

        priority_queue<pair<int,char> ,vector<pair<int,char>> ,cmp>pq;
        unordered_map<char , int> f;
        for(int i = 0 ; i < s.size();i++){
            f[s[i]]++;
        };
        for(auto i : f){
            char letter = i.first;
            int freq = i.second;

            pair<int,char> p = {freq , letter};
            pq.push(p);
        };

        string res = "";
        int seat = 0;
        while(!pq.empty()){
            pair<int , char> p = pq.top();
            pq.pop();
            if(seat == 0 || res[seat - 1] != p.second){
                res.push_back(p.second);
                seat++;
                p.first--;
                if(p.first > 0) pq.push(p);
            }
            else{
                if(pq.empty()) return "";
                pair<int , char> p2 = pq.top();
                pq.pop();
                res.push_back(p2.second);
                p2.first--;
                seat++;
                if(p2.first > 0) pq.push(p2);

                pq.push(p);
            };
        };

        return res;
        
    }
};