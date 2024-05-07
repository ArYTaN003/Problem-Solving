class Solution {
public:
    /*
    Recursive/Memoization
    int rec(int n,vector<int>& dp) {
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=rec(n-1,dp)+rec(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return rec(n,dp);
    }
    */
    /*
    DP
    dp[i] -> Number of ways to climb i stairs.

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[1] = 1;
        dp[0] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    */
   int climbStairs(int n) {
        int prev1 = 1; // for n=0
        int prev2 = 1; // for n=1
        int c;
        for(int i=2;i<=n;i++){
            c=prev1+prev2;
            prev1=prev2;
            prev2=c;
        }
        return prev2;
    }
};