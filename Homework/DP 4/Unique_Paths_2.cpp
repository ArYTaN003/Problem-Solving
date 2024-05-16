class Solution {
public:
    /*
    Recursive/Memoization
    int getPaths(vector<vector<int>>& grid,int & m,int &n,int i,int j,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=getPaths(grid,m,n,i+1,j,dp)+getPaths(grid,m,n,i,j+1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return getPaths(grid,m,n,0,0,dp);
    }
    */
    /*
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        // dp[i][j] -> Number of unique paths to reach (i,j)
        dp[0][0] = grid[0][0]!=1;
        for(int i=1;i<m;i++){
            if(grid[i][0]!=1) dp[i][0]=dp[i-1][0];
        }
        for(int i=1;i<n;i++){
            if(grid[0][i]!=1) dp[0][i]=dp[0][i-1];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]!=1) dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
    */
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<long long> prev(n,0);
        vector<long long> curr(n,0);
        prev[n-1] = grid[m-1][n-1]!=1;
        for(int i=n-2;i>=0;i--){
            if(grid[m-1][i]!=1) prev[i]=prev[i+1];
        }
        for(int i=m-2;i>=0;i--){
            if(grid[i][n-1]==0) curr[n-1] = prev[n-1];
            else curr[n-1] = 0; 
            for(int j=n-2;j>=0;j--){
                if(grid[i][j]!=1) curr[j]=curr[j+1]+prev[j];
                else curr[j] = 0;
            }
            prev = curr;
        }
        return prev[0];
    }
};