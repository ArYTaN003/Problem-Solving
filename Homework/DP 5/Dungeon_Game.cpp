class Solution {
public:
    /*
    Memoization/Recursion
    dp[r][c] -> Min Health to reach n-1,m-1 cell from r,c
    int getMinHP(vector<vector<int>>& dungeon,int r,int c,int n,int m,vector<vector<int>>& dp){
        if(r>=n || c>=m) return INT_MAX;
        if(r==n-1 && c==m-1){
            if(dungeon[r][c]<=0){
                return -dungeon[r][c]+1;
            }else{
                return 1;
            }
        }
        if(dp[r][c]!=-1) return dp[r][c];
        if(dungeon[r][c]<=0){
            return dp[r][c] = min(getMinHP(dungeon,r+1,c,n,m,dp),getMinHP(dungeon,r,c+1,n,m,dp))-dungeon[r][c];
        }else{
            return dp[r][c] = max(1,min(getMinHP(dungeon,r+1,c,n,m,dp),getMinHP(dungeon,r,c+1,n,m,dp))-dungeon[r][c]);
        }
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(),m=dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return getMinHP(dungeon,0,0,n,m,dp);
    }
    */

    /*
    DP
    dp[r][c] -> Min Health to reach n-1,m-1 from r,c
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(),m=dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        dp[n-1][m-1] = dungeon[n-1][m-1]<=0?-dungeon[n-1][m-1]+1:1;
        for(int i=n-2;i>=0;i--){
            dp[i][m-1] = -dungeon[i][m-1]+dp[i+1][m-1];
            // dp[i][m-1]<=0 , means that the amount of health received is more than
            // than what is required to go to next cell , so we set it to 1 
            // since 1 is the min value we can have in this case  
            if(dp[i][m-1]<=0) dp[i][m-1] = 1;
        }
        for(int i=m-2;i>=0;i--){
            dp[n-1][i] = -dungeon[n-1][i]+dp[n-1][i+1];
            if(dp[n-1][i]<=0) dp[n-1][i] = 1; 
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                dp[i][j] = -dungeon[i][j]+min(dp[i+1][j],dp[i][j+1]);
                if(dp[i][j]<=0) dp[i][j] = 1;
            }
        }
        return dp[0][0];
    }
    */
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(),m=dungeon[0].size();
        vector<int> prev(m);
        prev[m-1] = dungeon[n-1][m-1]<=0?-dungeon[n-1][m-1]+1:1;
        for(int i=m-2;i>=0;i--){
            prev[i] = -dungeon[n-1][i]+prev[i+1];
            if(prev[i]<=0) prev[i] = 1;
        }
        vector<int> curr(m);
        for(int i=n-2;i>=0;i--){
            curr[m-1] = -dungeon[i][m-1]+prev[m-1];
            if(curr[m-1]<=0) curr[m-1] = 1;
            for(int j=m-2;j>=0;j--){
                curr[j] = -dungeon[i][j]+min(prev[j],curr[j+1]);
                if(curr[j]<=0) curr[j] =1;
            }
            prev = curr;
        }
        return prev[0];
    }
};