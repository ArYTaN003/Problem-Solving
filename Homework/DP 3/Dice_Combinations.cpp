#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
/*
recursive/memoization

int getWays(int n,vector<int>& dp){
  if(n<=1) return 1;
  if(dp[n]!=-1) return dp[n];
  int ans = 0;
  // cout << n << endl;

  for(int i=1;i<=6 && n-i>=0;i++){
    ans = (ans+getWays(n-i,dp))%mod;
  }
  return dp[n]=ans;

}
*/
int main()
{
  
  int n;
  cin >> n;
  vector<int> dp(n+1,0);
  // dp[i] -> Number of ways to get sum i
  dp[0] = 1;
  for(int i=1;i<=n;i++){
    for(int j =1;i-j>=0 && j<=6;j++){
      dp[i]=(dp[i]+dp[i-j])%mod;
    }
  }
  cout << dp[n] << endl;
  return 0;
}
