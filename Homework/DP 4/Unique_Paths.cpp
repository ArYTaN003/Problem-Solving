class Solution {
public:
    /*
    Recursive/Memoization
    int getPaths(int& m,int& n,int i,int j,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=getPaths(m,n,i+1,j,dp)+getPaths(m,n,i,j+1,dp);
    }
    int uniquePaths(int m, int n){
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return getPaths(m,n,0,0,dp);
    }
    */
    /*
    DP

    int uniquePaths(int m, int n){
        vector<vector<int>> dp(m,vector<int>(n,0));
        // dp[i][j] = number of unique paths to reach (m-1,n-1) from (i,j)
        for(int i=m-1;i>=0;i--){
            dp[i][n-1] = 1;
        }
        for(int i=n-1;i>=0;i--){
            dp[m-1][i] = 1;
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j] = dp[i+1][j]+dp[i][j+1]; 
            }
        }
        return dp[0][0];
    }
    */
    int uniquePaths(int m, int n){
        vector<int> prev(n,1);
        vector<int> curr(n,1);
        for(int i=m-2;i>=0;i--){
            curr[n-1] = 1;
            for(int j=n-2;j>=0;j--){
                curr[j] = prev[j]+curr[j+1]; 
            }
            prev = curr;
        }
        return prev[0];
    }
};