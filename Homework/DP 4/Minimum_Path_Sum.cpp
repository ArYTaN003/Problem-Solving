class Solution {
public:
    /*
    Recursive/Memoization
    int rec(vector<vector<int>>& grid,int r,int c,int& m,int& n,vector<vector<int>>& dp){
        if(r>=m || c>=n) return INT_MAX;
        if(r==m-1  && c==n-1) return grid[r][c];
        if(dp[r][c]!=-1) return dp[r][c];
        return dp[r][c]=grid[r][c]+min(rec(grid,r+1,c,m,n,dp),rec(grid,r,c+1,m,n,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return rec(grid,0,0,m,n,dp);
    }
    */
    /*
    DP

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        // dp[i][j] -> Min Sum To reach (i,j)
        dp[0][0] = grid[0][0];
        for(int i=1;i<n;i++){
            dp[0][i]=grid[0][i]+dp[0][i-1];
        }
        for(int i=1;i<m;i++){
            dp[i][0] = grid[i][0]+dp[i-1][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
    */
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<int> prev(n,INT_MAX);
        vector<int> curr(n,INT_MAX);
        prev[0] = grid[0][0];
        for(int i=1;i<n;i++){
            prev[i]=grid[0][i]+prev[i-1];
        }
        for(int i=1;i<m;i++){
            curr[0] = grid[i][0]+prev[0];
            for(int j=1;j<n;j++){
                curr[j] = grid[i][j]+min(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        return prev[n-1];
    }
};