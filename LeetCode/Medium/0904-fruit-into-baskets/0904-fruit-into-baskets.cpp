class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> f;
        int low = 0 , high = 0 ;
        int res = 0;
        while(high < fruits.size()){
            f[fruits[high]]++;
            while(f.size() > 2){
                f[fruits[low]]--;
                if(f[fruits[low]] ==  0 ) f.erase(fruits[low]);
                low++;

            }
            if(f.size() <=2){
                int len = high - low + 1;
                res = max(res , len);
            }
            high++;
        }

        return res;
        
    }
};