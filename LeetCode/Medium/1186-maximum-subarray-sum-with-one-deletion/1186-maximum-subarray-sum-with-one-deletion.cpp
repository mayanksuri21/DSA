class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        
        int noDel = arr[0];   // max subarray ending here without deletion
        int oneDel = 0;       // max subarray ending here with one deletion
        int res = arr[0];

        for (int i = 1; i < n; i++) {
            int prevNoDel = noDel;

            // normal Kadane
            noDel = max(arr[i], noDel + arr[i]);

            // either extend previous deletion OR delete current element
            oneDel = max(oneDel + arr[i], prevNoDel);

            res = max(res, max(noDel, oneDel));
        }

        return res;
    }
};