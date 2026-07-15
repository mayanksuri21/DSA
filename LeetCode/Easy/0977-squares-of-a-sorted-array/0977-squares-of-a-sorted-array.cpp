class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // for(int i = 0 ;i<nums.size();i++){
        //     nums[i] *= nums[i];
        // }
        // sort(nums.begin(),nums.end());

        // return nums;

        // follow up of this ques don't use sort func

        vector<int>neg;
        vector<int>pos;

        for(int i = 0 ;i<nums.size();i++){
            if(nums[i] < 0){
                neg.push_back(nums[i]);
            }
            else pos.push_back(nums[i]);
        }

        if(neg.size() == 0){ //  full positve array
            for(int i = 0 ; i < pos.size() ; i++){
                pos[i] *= pos[i];

            }
            return pos;

        }
        if(pos.size() == 0){ //  full negative  array
            for(int i = 0 ; i < neg.size() ; i++){
                neg[i] *= neg[i];

            }
            reverse(neg.begin(),neg.end());
            return neg;

        }
        else{ // neg + pos array
            int i = 0 , j = 0 , id = 0;
            int n = neg.size();
            int m = pos.size();
            vector<int>res(n+m);

            for(int i = 0 ; i < n ; i++){
                neg[i] *= neg[i];

            }
            reverse(neg.begin(),neg.end());

            for(int i = 0 ; i < m ; i++){
                pos[i] *= pos[i];

            }

            while(i<n && j<m){
                if(neg[i] <= pos[j]){
                    res[id++] = neg[i];
                    i++;
                }
                else{
                    res[id++] = pos[j];
                    j++;
                }
            }
            while(i<n){
                res[id++] = neg[i];
                i++;

            }
            while(j<m){
                res[id++] = pos[j];
                j++;

            }


            return res;



        }
        
    }
};