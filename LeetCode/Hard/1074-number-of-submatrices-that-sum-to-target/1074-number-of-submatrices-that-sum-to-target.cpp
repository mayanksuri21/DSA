class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // cumulative sum matrix

        for(int row = 0 ; row < rows;row++){
            for(int col = 1; col < cols; col++){
                matrix[row][col] += matrix[row][col-1];
            }
        }

        // now findind no. of subarrays with sum == target ( lc 560) downwards

        int res = 0;

        for(int startcol = 0; startcol < cols; startcol++){
            for(int j = startcol ; j< cols; j++){
                int currsum = 0;
                unordered_map<int, int>f;
                f.insert({0,1});

                for(int row = 0 ; row < rows; row++){
                    currsum += matrix[row][j] - (startcol > 0 ? matrix[row][startcol -1] : 0);

                    if(f.find(currsum - target) != f.end()){
                        res += f[currsum - target];
                    }
                    f[currsum]++;
                }


            }
        }

        return res;
        
    }
};