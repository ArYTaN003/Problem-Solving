class Solution {
public:
    /*
    Recursive/Memoization
    int rec(int amount,vector<int>& coins,int curr, vector<vector<int>>& memo){
        if(amount==0){
            return 1;
        }
        if(curr==coins.size()){
            return 0;
        }
        if(memo[curr][amount]!=-1){
            return memo[curr][amount];
        }
        int ans = 0;
        for(int i=curr;i<coins.size();i++){
            if(coins[i]>amount) continue;
            ans += rec(amount-coins[i],coins,i,memo);
        }
        return  memo[curr][amount]=ans;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1,-1));
        return rec(amount,coins,0,dp);
    }
    */
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int> dp(amount+1,0);
        // dp[i] -> Number of ways to get i amount 
        dp[0] = 1;
        for(int i=0;i<n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i]<=j) dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};