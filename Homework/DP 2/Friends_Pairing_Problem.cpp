class Solution
{
    int mod = 1e9+7;
public:
    /*
    Memoization/Recursion
    
    long long ways(int n,vector<long long>& dp){
        if(n<=2) return n;
        if(dp[n]!=-1) return dp[n]%mod;
        return dp[n]=((ways(n-1,dp))%mod+((n-1)%mod)*(ways(n-2,dp)%mod))%mod;
    }
    int countFriendsPairings(int n) 
    { 
        
        vector<long long> dp(n+1,-1);
        return ways(n,dp);
    }
    */
    /*
    DP
    
    int countFriendsPairings(int n) 
    { 
        
        vector<long long> dp(n+1,-1);
        dp[1] = 1;
        dp[2] = 2;
        // dp[i]-> Number of ways i people can party
        for(int i=3;i<=n;i++){
            dp[i] = (dp[i-1]+(i-1)*dp[i-2])%mod;
        }
        return dp[n];
    }
    */
    
    int countFriendsPairings(int n) 
    { 
        if(n<=2) return n;
        long long prev1 = 2; // curr-1
        long long prev2 = 1; // curr-2
        long long curr;
        for(int i=3;i<=n;i++){
            curr = (prev1+(i-1)*prev2)%mod;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};    