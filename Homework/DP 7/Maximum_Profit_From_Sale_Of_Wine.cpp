
#include <bits/stdc++.h>
using namespace std;

/*
Recursive/Memoization

int rec(int price[], int i,int j, int n,vector<vector<int>>& dp,vector<vector<bool>>& seq) {
	if(i==j){
      	seq[i][j] = true;
    	return n*price[i];
    }
  	if(dp[i][j]!=-1) return dp[i][j];
	int year = n - (j - i);
	int op1 = price[i] * year + rec(price, i+1, j, n,dp,seq);
	int op2 = price[j] * year + rec(price, i, j-1, n,dp,seq);
  	if(op1>op2) seq[i][j] = true;
	return dp[i][j]=max(op1,op2);
}
*/
/*
DP

int maxProfit(int price[], int n) {
  	vector<vector<int>> dp(n,vector<int>(n,0));
  	vector<vector<bool>> seq(n,vector<bool>(n,false));
  	for(int i=0;i<n;i++){
    	dp[i][i] = n*price[i];
      	seq[i][i] = true;
    }
  	for(int i=n-2;i>=0;i--){
    	for(int j=i+1;j<n;j++){
        	dp[i][j] = max(price[i]*(n-(j-i))+dp[i+1][j],
                           price[j]*(n-(j-i))+dp[i][j-1]);
          	if(price[i]*(n-(j-i))+dp[i+1][j]>price[j]*(n-(j-i))+dp[i][j-1]){
            	seq[i][j] = true;
            }
        }
    }
  	int i=0,j=n-1;
  	while(i<=j){
    	if(seq[i][j]){
        	cout << "beg ";
          i++;
        }else{
        	cout << "end ";
          j--;
        }
    }
    cout << endl;
	return dp[0][n-1];
}
*/
int maxProfit(int price[], int n) {
  	vector<int> prev(n,0);
    vector<int> curr(n,0);
  	vector<string> prev_seq(n,"");
    vector<string> curr_seq(n,"");
    prev_seq[n-1] = "beg";
  	prev[n-1] = n*price[n-1];
  	for(int i=n-2;i>=0;i--){
        curr[i] = n*price[i];
        curr_seq[i] = "beg ";
    	for(int j=i+1;j<n;j++){
        	curr[j] = max(price[i]*(n-(j-i))+prev[j],price[j]*(n-(j-i))+curr[j-1]);
          	if(price[i]*(n-(j-i))+prev[j]>price[j]*(n-(j-i))+curr[j-1]){
            	curr_seq[j] = "beg "+prev_seq[j];
            }else{
                curr_seq[j] = "end "+curr_seq[j-1];
            }
        }
        prev = curr;
        prev_seq = curr_seq;
    }
  	cout << prev_seq[n-1] << endl;
	return prev[n-1];
}

int main() {
	int price[] = { 2, 4, 6, 2, 5 };

	int n = sizeof(price) / sizeof(price[0]);

	int ans = maxProfit(price, n);

	cout << ans << endl;

	return 0;
}
