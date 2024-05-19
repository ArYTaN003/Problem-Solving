class Solution {
public:
    /*
    Recursive/Memoization
    int rec(vector<vector<int>>& grid,vector<vector<int>>& moveCost,int row,int col,vector<vector<int>>& dp){
        if(row==grid.size()-1) return grid[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int minCost = INT_MAX;
        for(int i=0;i<grid[0].size();i++){
            minCost = min(minCost,moveCost[grid[row][col]][i]+rec(grid,moveCost,row+1,i,dp));
        }
        return dp[row][col]=grid[row][col]+minCost;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int minCost = INT_MAX;
        int n = grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<grid[0].size();i++){
            minCost = min(minCost,rec(grid,moveCost,0,i,dp));
        }
        return minCost;
    }
    */
    /*
    DP

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int minCost = INT_MAX;
        int n = grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        // dp[i][j] -> Min cost to reach n-1th row from (i,j)
        for(int i=0;i<m;i++){
            dp[n-1][i] = grid[n-1][i];
        }
        for(int row=n-2;row>=0;row--){
            for(int col=0;col<m;col++){
                dp[row][col] = INT_MAX;
                for(int i=0;i<m;i++){
                    dp[row][col] = min(dp[row][col],grid[row][col]+moveCost[grid[row][col]][i]+dp[row+1][i]);
                }
            }
        }
        for(int i=0;i<m;i++){
            minCost = min(minCost,dp[0][i]);
        }
        return minCost;
    }
    */
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int minCost = INT_MAX;
        int n = grid.size(),m=grid[0].size();
        vector<int> prev(m,0);
        vector<int> curr(m,0);
        for(int i=0;i<m;i++){
            prev[i] = grid[n-1][i];
        }
        for(int row=n-2;row>=0;row--){
            for(int col=0;col<m;col++){
                curr[col] = INT_MAX;
                for(int i=0;i<m;i++){
                    curr[col] = min(curr[col],grid[row][col]+moveCost[grid[row][col]][i]+prev[i]);
                }
            }
            prev = curr;
        }
        for(int i=0;i<m;i++){
            minCost = min(minCost,prev[i]);
        }
        return minCost;
    }
};