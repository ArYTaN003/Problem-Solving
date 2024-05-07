class Solution {
public:
    /*
    Recursive/Memoization

    long long helper(vector<vector<int>>& ques,int curr,int n,vector<long long>&dp){
        if(curr>=n) return 0;
        if(dp[curr]!=-1) return dp[curr];
        long long inc = ques[curr][0]+helper(ques,curr+ques[curr][1]+1,n,dp);
        long long exc = helper(ques,curr+1,n,dp);
        return dp[curr]=max(inc,exc);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,-1);
        return helper(questions,0,n,dp);
    }
    */
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,0);
        dp[n-1] = questions[n-1][0];
        // dp[i] -> Max Points we can get at index i , whether including it or excluding it.
        for(int i=n-2;i>=0;i--){
            dp[i]=questions[i][0];
            dp[i]+=(i+questions[i][1]+1<n?dp[i+questions[i][1]+1]:0);
            dp[i] = max(dp[i],dp[i+1]);
        }
        return dp[0];
    }
};