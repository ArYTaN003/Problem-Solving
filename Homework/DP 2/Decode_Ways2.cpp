class Solution {
    unordered_map<string,string> mp={
    {"1","A"},{"2","B"},{"3","C"},{"4","D"},{"5","E"},{"6","F"},
    {"7","G"},{"8","H"},{"9","I"},{"10","J"},{"11","K"},
    {"12","L"},{"13","M"},{"14","N"},{"15","O"},{"16","P"},
    {"17","Q"},{"18","R"},{"19","S"},{"20","T"},{"21","U"},
    {"22","V"},{"23","W"},{"24","X"},{"25","Y"},{"26","Z"}};
    int mod = 1e9+7;
public:
    /*
    Recursive/Memoization
    
    int rec(string &s,int curr,vector<int>& dp){
        if(s.length()<=curr) return 1;
        if(s[curr]=='0') return 0;
        if(dp[curr]!=-1) return dp[curr];
        // If s[curr]!='0' we can always decode a single character
        int ways = rec(s,curr+1,dp);
        // If s[curr]='*' , we can decode this character in 9 ways
        if(s[curr]=='*') ways=(ways*9LL)%mod;
        if(s.length()>curr+1){
            if(s[curr]=='*'){
                if(s[curr+1]=='*'){
                    // s='**'
                    ways=(ways+15LL*rec(s,curr+2,dp)%mod)%mod;
                }else{
                    if(s[curr+1]>='0' && s[curr+1]<='6'){
                        //s = '*x' , x = [0,6]
                        ways=(ways+2LL*rec(s,curr+2,dp)%mod)%mod;
                    }else{
                        // s='*y' , y = [7,9]
                        ways=(ways+rec(s,curr+2,dp))%mod;
                    } 
                }
            }else if(s[curr+1]=='*'){
                // s='1*' or s='2*'
                if(s[curr]=='1'){
                    ways=(ways+9LL*rec(s,curr+2,dp)%mod)%mod;
                }else if(s[curr]=='2'){
                    ways=(ways+6LL*rec(s,curr+2,dp)%mod)%mod;
                }
            }
            else if(mp.find(s.substr(curr,2))!=mp.end()){
                // s = 'dd' , d-> digit
                ways=(ways+rec(s,curr+2,dp))%mod;
            }
        }
        return dp[curr]=ways;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n,-1);
        return rec(s,0,dp);
    }
    */
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int n = s.length();
        vector<int> dp(n+1,0);
        // dp[i] -> Number of ways to decode [0,i] substring of s 
        dp[0] = 1;
        dp[1] = s[0]=='*'?9:1;
        for(int i=2;i<=n;i++){
            if(s[i-1]!='0'){
                dp[i] = dp[i-1];
                if(s[i-1]=='*') dp[i]=(dp[i]*9LL)%mod;
            }
            if(s[i-2]=='*'){
                if(s[i-1]=='*') dp[i]=(dp[i]+15LL*dp[i-2])%mod;
                else {
                    if(s[i-1]>='0' && s[i-1]<='6')dp[i]=(dp[i]+2LL*dp[i-2])%mod;
                    else dp[i]=(dp[i]+dp[i-2])%mod;
                }
            }else if(s[i-2]!='0'){
                if(s[i-1]=='*'){
                    if(s[i-2]=='1'){
                        dp[i]=(dp[i]+9LL*dp[i-2])%mod;
                    }else if(s[i-2]=='2'){
                        dp[i]=(dp[i]+6LL*dp[i-2])%mod;
                    }
                }else if(mp.find(s.substr(i-2,2))!=mp.end()){
                    dp[i]=(dp[i]+dp[i-2])%mod;
                }
            }
        }
        return dp[n];
    }
};