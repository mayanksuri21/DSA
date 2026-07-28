class Solution {
public:
    bool valid(int i , int j , int m , int n){
        if((i<0 || i >= m) || (j <0 || j>=n)) return false;
        return true;
    }

    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    void dfs(vector<vector<char>>& board , int m , int n , int i ,  int j){
        board[i][j] = '#';
        for(int k = 0 ; k<4;k++){
            int row = i + x[k];
            int col = j + y[k];
            if(valid(row , col , m , n) && board[row][col] == 'O'){
                dfs(board , m , n , row, col );
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int i , j;
        // first row wale O
        for(j = 0 ; j<n;j++){
            if(board[0][j] == 'O'){
                dfs(board , m , n , 0 , j);
            }
        }
        // last row
        for(j = 0 ; j<n;j++){
            if(board[m-1][j] == 'O'){
                dfs(board , m , n , m-1 , j);
            }
        }

        // first col
        for(i = 0 ; i<m;i++){
            if(board[i][0] == 'O'){
                dfs(board , m , n , i , 0);
            }
        } 
        // last col
        for(i = 0 ; i<m;i++){
            if(board[i][n-1] == 'O'){
                dfs(board , m , n , i , n-1);
            }
        }
        

        for(i = 0 ; i <m;i++){
            for(j= 0 ; j < n;j++){
                if(board[i][j] == '#') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }

        return;
    }
};