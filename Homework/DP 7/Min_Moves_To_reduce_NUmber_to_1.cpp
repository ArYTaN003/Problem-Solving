/*
Recursive/Memoization
int rec(int n,vector<int>& dp){
    if(n==1) return 0;
    if(dp[n]!=-1) return dp[n];
    int op2 = INT_MAX,op3=INT_MAX;
    if(n%2==0){
        op2 = rec(n/2,dp);
    }
    if(n%3==0 && (n-(n/3)*2)>=0){
        op3 = rec(n-(n/3)*2,dp);
    }
    int op1=rec(n-1,dp);
    return dp[n]=1+min(op1,min(op2,op3));
}
int minMoves(int n) {
    vector<int> dp(n+1,-1);
    return rec(n,dp);
}
*/
int minMoves(int n) {
    vector<int> dp(n+1,0);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    // dp[i] -> Min MOves to reduce i to 1
    for(int i=4;i<=n;i++){
        dp[i] = 1+dp[i-1];
        if(i%2==0) dp[i] = min(dp[i],dp[i/2]+1);
        if(i%3==0) dp[i] = min(dp[i],dp[i/3]+1);
    }
    return dp[n];
}