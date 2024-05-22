class Solution {
public:
    /*
    Recuirsive/Memoization
    int rec(string& text1,string&text2,int i,int j,vector<vector<int>>& dp){
        if(i==text1.length() || j==text2.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int inc = 0;
        if(text1[i]==text2[j]){
            inc = rec(text1,text2,i+1,j+1,dp)+1;
        }
        int exc = max(rec(text1,text2,i+1,j,dp),rec(text1,text2,i,j+1,dp));
        return dp[i][j]=max(inc,exc);

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(),m=text2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return rec(text1,text2,0,0,dp);
    }
    */
    /*
    DP
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(),m=text2.length();
        vector<vector<int>> dp(n,vector<int>(m,0));
        // dp[i][j] -> Longest Common Sequence in text1[0:i] , text2[0:j]
        dp[0][0] = text1[0]==text2[0];
        for(int i=1;i<m;i++){
            dp[0][i] = max(dp[0][i-1],(int)(text1[0]==text2[i]));
        }
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0],(int)(text1[i]==text2[0]));
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(text1[i]==text2[j]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                // cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
        return dp[n-1][m-1];
    }
    */
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(),m=text2.length();
        vector<int> prev(m,0);
        vector<int> curr(m,0);
        prev[0] = text1[0]==text2[0];
        for(int i=1;i<m;i++){
            prev[i] = max(prev[i-1],(int)(text1[0]==text2[i]));
        }
        for(int i=1;i<n;i++){
            curr[0] = max(prev[0],(int)(text1[i]==text2[0]));
            for(int j=1;j<m;j++){
                if(text1[i]==text2[j]){
                    curr[j] = 1+prev[j-1];
                }else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[m-1];
    }
};