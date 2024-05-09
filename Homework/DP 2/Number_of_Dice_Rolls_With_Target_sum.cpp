class Solution {
    int mod = 1e9+7;
public:
    /*
    Memoization/Recursive

    int rec(int n,int k,int target,vector<vector<int>>& dp){
        if(n==0 && target==0) return 1;
        if(n==0 || target<=0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        int ways = 0;
        for(int i=1;i<=k;i++){
            ways=(ways+rec(n-1,k,target-i,dp))%mod;
        }
        return dp[n][target]=ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return rec(n,k,target,dp);
    }
    */
    /*
    DP

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        // dp[i][j] -> Number of ways to get sum j using i dices
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                for(int m=1;m<=k && j-m>=0;m++){
                    dp[i][j] = (dp[i][j]+dp[i-1][j-m])%mod;
                }
            }
        }
        return dp[n][target];
    }
    */
    int numRollsToTarget(int n, int k, int target) {
        vector<int> prev(target+1,0);
        prev[0] = 1;
        vector<int> curr(target+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                curr[j] = 0;
                for(int m=1;m<=k && j-m>=0;m++){
                    curr[j] = (curr[j]+prev[j-m])%mod;
                }
            }
            prev = curr;
        }
        return prev[target];
    }
};