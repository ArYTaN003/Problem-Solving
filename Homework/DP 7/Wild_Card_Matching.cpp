class Solution {
public:
    /*
    Recursive/Memoization

    bool rec(string& s,string& p,int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i==m && j==n) return true;
        else if(i==m || j==n){
            if(j==n) return false;
            else{
                for(int k=j;k<n;k++){
                    if(p[k]!='*') return false;
                }
                return true;
            }
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=rec(s,p,i+1,j+1,m,n,dp);
        }else if(p[j]=='*'){
            while(j+1<n && p[j]==p[j+1]) j++;
            for(int k=i;k<=m;k++){
                if(rec(s,p,k,j+1,m,n,dp)) return dp[i][j]=1;
            }
            return dp[i][j]=false;
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int m = s.length(),n=p.length();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return rec(s,p,0,0,m,n,dp);
    }
    */
    /*
    DP
    bool isMatch(string s, string p) {
        int m = s.length(),n=p.length();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        // dp[i][j] -> Is String s[0:i-1] matching p[0:j-1]
        dp[0][0] = true;
        for(int i=1;i<=n;i++){
            dp[0][i] = (dp[0][i-1] && p[i-1]=='*');
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]!='*'){
                    dp[i][j] = (p[j-1]=='?' || p[j-1]==s[i-1]) && dp[i-1][j-1];
                }else{
                    // dp[i][j-1] -> since s[0:i-1] matches p[0:j-2] , means '*' can be empty
                    // dp[i-1][j] -> since s[0:i-2] matches p[0:j-1] , means '*' can contain some sequence of characters , or a single character.
                    dp[i][j] = (dp[i][j-1] || dp[i-1][j]);
                }
            }
        }
        return dp[m][n];
    }
    */
    bool isMatch(string s, string p) {
        int m = s.length(),n=p.length();
        vector<bool> prev(n+1,false);
        vector<bool> curr(n+1,false);
        prev[0] = true;
        for(int i=1;i<=n;i++){
            prev[i] = (prev[i-1] && p[i-1]=='*');
        }
        for(int i=1;i<=m;i++){
            curr[0] = false;
            for(int j=1;j<=n;j++){
                if(p[j-1]!='*'){
                    curr[j] = (p[j-1]=='?' || p[j-1]==s[i-1]) && prev[j-1];
                }else{
                    curr[j] = (curr[j-1] || prev[j]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};