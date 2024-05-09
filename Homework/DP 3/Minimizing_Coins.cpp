#include <bits/stdc++.h>
using namespace std;
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
    int coinChange(vector<int>& coins, int amount,int n) {
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int num = rec(coins,0,amount,dp);
        return num==INT_MAX?-1:num;
    }
    */
int coinChange(vector<int>& coins, int amount,int n) {
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
int main()
{
    int n,x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin >> coins[i];
    }
    cout << coinChange(coins,x,n) << endl;
    return 0;
}