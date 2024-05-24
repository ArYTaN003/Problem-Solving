class Solution {
public:
    /*
    Recursive/Memoization
    
    int rec(string& word1,string& word2,int curr1,int curr2,vector<vector<int>>& dp){
        if(curr1==word1.length() && curr2==word2.length()){
            return 0;
        }
        else if(curr2==word2.length()){
            return word1.length()-curr1;
        }
        else if(curr1==word1.length()){
            return word2.length()-curr2;
        }
        if(dp[curr1][curr2]!=-1) return dp[curr1][curr2];
        if(word1[curr1]!=word2[curr2]){
            int replace = rec(word1,word2,curr1+1,curr2+1,dp);
            int del = rec(word1,word2,curr1+1,curr2,dp);
            int insert = rec(word1,word2,curr1,curr2+1,dp);
            return dp[curr1][curr2]=1+min(replace,min(del,insert));
        }
        return dp[curr1][curr2]=rec(word1,word2,curr1+1,curr2+1,dp);
    }
    int minDistance(string word1, string word2) {
        int n = word1.length(),m=word2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return rec(word1,word2,0,0,dp);
    }
    */
    
    /*
    DP

    int minDistance(string word1, string word2) {
        int n = word1.length(),m=word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // dp[i][j] -> Min operations to convert word1 substring of length i, into word2 substring of length j
        for(int i=0;i<=m;i++){
            // for all substrings of word1 of length 0 , we need to insert all characters , of word2 substring
            // of length i
            dp[0][i] = i;
        }
        for(int i=0;i<=n;i++){
            // for all substrings of word2 of length 0 , we need to delete all i characters , of word1
            // to get substring of length 0
            dp[i][0] = i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }
    */
    int minDistance(string word1, string word2) {
        int n = word1.length(),m=word2.length();
        vector<int> prev(m+1,0);
        for(int i=0;i<=m;i++){
            prev[i] = i;
        }
        // prev[i] -> Min operations to convert into word2 substring of length i 
        vector<int> curr(m+1,0);
        for(int i=1;i<=n;i++){
            // To convert word1 substring of length i , into word2 substring of length 0
            // we need i delete operations
            curr[0] = i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j] = prev[j-1];
                }else{
                    curr[j] = 1+min(prev[j-1],min(prev[j],curr[j-1]));
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};