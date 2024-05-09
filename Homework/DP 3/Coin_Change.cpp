class Solution {
public:
    /*
    Memoization/Recusion

    int rec(vector<int>& coins,int curr,int amount,vector<vector<int>>& dp){
        if(amount==0) return 0;
        if(curr==coins.size() || amount<0) return INT_MAX;
        if(dp[curr][amount]!=-1) return dp[curr][amount];
        int op1 = rec(coins,curr,amount-coins[curr],dp);
        int op2 = rec(coins,curr+1,amount-coins[curr],dp);
        int op3 = rec(coins,curr+1,amount,dp);
        if(op1!=INT_MAX) op1++;
        if(op2!=INT_MAX) op2++;
        return dp[curr][amount]=min(op1,min(op2,op3));
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int num = rec(coins,0,amount,dp);
        return num==INT_MAX?-1:num;
    }
    */
    /*
    2-D DP
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n,INT_MAX));
        // dp[i][j]-> Min number of coins needed to get i amount using a coin of jth denomination
        for(int i=0;i<n;i++){
            dp[0][i] = 0;
        }
        for(int i=1;i<=amount;i++){
            for(int j = 0;j<n;j++){
                if(i-coins[j]<0) continue;
                int m = *min_element(dp[i-coins[j]].begin(),dp[i-coins[j]].end());
                if(m==INT_MAX) continue;
                dp[i][j] = min(dp[i][j],1+m);
            }
        }
        int min_ways = *min_element(dp[amount].begin(),dp[amount].end()); 
        return min_ways==INT_MAX?-1:min_ways;
    }
    */
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,-1);
        //dp[i] -> Min number of coins to get i amount
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j = 0;j<n;j++){
                if(i-coins[j]<0 || dp[i-coins[j]]==-1) continue;
                if(dp[i]!=-1) dp[i] = min(dp[i],1+dp[i-coins[j]]);
                else dp[i] = 1+dp[i-coins[j]];
            }
        }
        return dp[amount];
    }
};