//Top down approach, recur + memo
//time complexity - O(n^n * n), space complexity - O() without memo
//time complexity - O(n^3), space complexity - O(n^2) with memo
int n;
    int t[201][201];
    int solve(int col, int row, vector<vector<int>> &grid){
        if(row == n-1) return grid[row][col];
        if(t[row][col] != -1) return t[row][col];

        int ans = INT_MAX;
        for(int nextCol = 0; nextCol < n; nextCol++){
            if(nextCol != col) ans = min(ans, solve(nextCol, row+1, grid));
        }

        return t[row][col] =  ans + grid[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        memset(t, -1, sizeof(t));
        int result = INT_MAX;

        for(int col = 0; col < n; col++){
            result = min(result, solve(col, 0, grid));
        }
        return result;
    }
//Bottom up Approach
//time complexity - O(N^3), space complexity - O(N^2)
int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> t(n, vector<int>(n, INT_MAX));
        for(int col = 0; col < n; col++) t[n-1][col] = grid[n-1][col];

        for(int row = n-2; row >= 0; row--){
            for(int col = 0; col < n; col++){
                int ans = INT_MAX;
                for(int nextCol = 0; nextCol < n; nextCol++){
                    if(nextCol != col) ans = min(ans, t[row+1][nextCol]);
                }
                t[row][col] = grid[row][col] + ans;
            }
        }

        int result = INT_MAX;
        for(int col = 0; col < n; col++){
            result = min(result, t[0][col]);
        }

        return result;
    }
//Optimized Bottom up Approach time complexity - O(n^2), space complexity - O(n^2);
 int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> t(n, vector<int>(n, INT_MAX));
        int nextMinCol1 = -1, nextMinCol2 = -1;
        for(int col = 0; col < n; col++){
            t[n-1][col] = grid[n-1][col];
            if(nextMinCol1 == -1 || t[n-1][col] <= t[n-1][nextMinCol1]){
                nextMinCol2 = nextMinCol1;
                nextMinCol1 = col;
            }else if(nextMinCol2 == -1 || t[n-1][col] <= t[n-1][nextMinCol2]){
                nextMinCol2 = col;
            }
        }

        for(int row = n-2; row >= 0; row--){
            int minCol1 = -1, minCol2 = -1;
            for(int col = 0; col < n; col++){
                
               if(col != nextMinCol1) t[row][col] = grid[row][col] + t[row+1][nextMinCol1];
               else t[row][col] = grid[row][col] + t[row+1][nextMinCol2];

               if(minCol1 == -1 || t[row][col] <= t[row][minCol1]){
                minCol2 = minCol1;
                minCol1 = col;
               }else if(minCol2 == -1 || t[row][col] <= t[row][minCol2]){
                minCol2 = col;
               }
            }
            nextMinCol1 = minCol1;
            nextMinCol2 = minCol2;
        }

        return t[0][nextMinCol1];
    }
//Constant Space Solution
//Time complexity - O(N^2)
int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        int nextMinCol1 = -1, nextMinCol2 = -1;
        int nextMinCol1Val = -1, nextMinCol2Val = -1;

        for(int col = 0; col < n; col++){
          
            if(nextMinCol1 == -1 || grid[n-1][col] <= nextMinCol1Val){
                nextMinCol2 = nextMinCol1;
                nextMinCol2Val = nextMinCol1Val;
                nextMinCol1 = col;
                nextMinCol1Val = grid[n-1][col];
            }else if(nextMinCol2 == -1 || grid[n-1][col] <= nextMinCol2){
                nextMinCol2 = col;
                nextMinCol2Val = grid[n-1][col];
            }
        }

        for(int row = n-2; row >= 0; row--){
            int minCol1 = -1, minCol2 = -1;
            int minCol1Val = -1, minCol2Val = -1;
            int ans = INT_MAX;

            for(int col = 0; col < n; col++){
                
                if(col != nextMinCol1){
                    ans = grid[row][col] + nextMinCol1Val;
                }else{
                    ans = grid[row][col] + nextMinCol2Val;
                }

                if(minCol1 == -1 || ans <= minCol1Val){
                    minCol2 = minCol1;
                    minCol2Val = minCol1Val;
                    minCol1 = col;
                    minCol1Val = ans;
                }else if(minCol2 == -1 || ans <= minCol2Val){
                    minCol2 = col;
                    minCol2Val = ans;
                }
                grid[row][col] += ans;
            }
            nextMinCol1 = minCol1;
            nextMinCol2 = minCol2;
            nextMinCol1Val = minCol1Val;
            nextMinCol2Val = minCol2Val;
            
        }

        return nextMinCol1Val;
    }