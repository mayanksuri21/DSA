class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), i = 0 , n= matrix[i].size() , j = n-1;

        while(i < m && j >=0){
            if(matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) i++;
            else j--;
        }

        return false;
        
        
    }
};