class Solution {
public:
    /*
    Recursive/Memoization
    int rec(vector<int>& nums,int k,int i,int j,int n,vector<vector<int>>& dp){
        if(k==0 || i>j) return 0;
        if(dp[i][n-j]!=-1) return dp[i][n-j]; 
        return dp[i][n-j]=max(nums[i]+rec(nums,k-1,i+1,j,n,dp),nums[j]+rec(nums,k-1,i,j-1,n,dp));
    }
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if(k==n){
            return accumulate(cardPoints.begin(),cardPoints.end(),0);
        }
        vector<vector<int>> dp(k+1,vector<int>(k+1,-1));
        return rec(cardPoints,k,0,n-1,n,dp);
    }
    */
    /*
    DP
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxScore = 0;
        vector<vector<int>> dp(k+1,vector<int>(k+1,0));
        // dp[i][j] -> Max Sum by Taking i elements from front , j elements form back
        dp[0][0] = 0;
        for(int i=1;i<=k;i++){
            dp[i][0] = cardPoints[i-1]+dp[i-1][0];
            dp[0][i] = cardPoints[n-i]+dp[0][i-1];
        }
        maxScore = max(dp[0][k],dp[k][0]);
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k-i;j++){
                dp[i][j] =  cardPoints[i-1]+cardPoints[n-j]+dp[i-1][j-1];
            }
            maxScore = max(dp[i][k-i],maxScore);
        }
        return maxScore;

    }
    */
    /*
    Better

    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxScore = 0;
        vector<int> front(k+1,0);
        vector<int> back(k+1,0);
        for(int i=1;i<=k;i++){
            front[i] = cardPoints[i-1]+front[i-1];
            back[i] = cardPoints[n-i]+back[i-1];
        }
        maxScore = max(front[k],back[k]);
        for(int i=1;i<k;i++){
            maxScore = max(front[i]+back[k-i],maxScore);
        }
        return maxScore;

    }
    */
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxScore = 0;
        int front = 0,back = 0;
        for(int i=1;i<=k;i++){
            front+= cardPoints[i-1];
        }
        maxScore = front;
        for(int i=1;i<=k;i++){
            front-=cardPoints[k-i];
            back+=cardPoints[n-i]; 
            maxScore = max(front+back,maxScore);
        }
        return maxScore;

    }
};