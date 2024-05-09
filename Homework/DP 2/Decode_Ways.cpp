class Solution {
   unordered_map<string,string> mp={{"1","A"},{"2","B"},{"3","C"},{"4","D"},{"5","E"},{"6","F"},{"7","G"},{"8","H"},{"9","I"},{"10","J"},{"11","K"},{"12","L"},{"13","M"},{"14","N"},{"15","O"},{"16","P"},{"17","Q"},{"18","R"},{"19","S"},{"20","T"},{"21","U"},{"22","V"},{"23","W"},{"24","X"},{"25","Y"},{"26","Z"}};  
public:
    /*
    Memoization/recursion

    int rec(string& s,int curr,vector<int>& dp){
        if(s.length()<=curr) return 1;
        if(s[curr]=='0') return 0;
        if(dp[curr]!=-1) return dp[curr];
        int ways = 0;
        if(curr+1<s.length() && mp.find(s.substr(curr,2))!=mp.end()){
            return dp[curr]=rec(s,curr+2,dp)+rec(s,curr+1,dp);
        }
        return dp[curr]=rec(s,curr+1,dp);
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
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            if(s[i-1]!='0') dp[i] = dp[i-1];
            if(mp.find(s.substr(i-2,2))!=mp.end()){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};