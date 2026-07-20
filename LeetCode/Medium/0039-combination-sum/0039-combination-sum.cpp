class Solution {
public:
    void func(vector<int>& a, int n, int idx, int target, int sum,
              vector<int>& diary, vector<vector<int>>& res) {

                if(idx == n ){
                    if(sum == target){
                        res.push_back(diary);
                    }
                    return;
                }
                func(a , n , idx+1,target,sum , diary , res); // choice 1-> el ko nhi lena 

                if(sum + a[idx] <= target){ // choice 2-> boht baar same el ko lena hai
                    diary.push_back(a[idx]);
                    sum += a[idx];
                    func(a,n,idx,target,sum,diary , res);
                    diary.pop_back();
                    sum -= a[idx];
                }

                return;

              }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum = 0;
        vector<int> diary;
        int idx = 0;
        vector<vector<int>> res;

        func(candidates, n, idx, target, sum, diary, res) ;
        return res;
    }
};