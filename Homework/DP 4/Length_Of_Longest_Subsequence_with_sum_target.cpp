class Solution {
public:
    /*
    Recursive/Memoization

    int rec(vector<int>& nums,int curr,int target,vector<vector<int>>& dp){
        if(target==0) return 0;
        if(curr==nums.size() || target<0) return -1;
        if(dp[curr][target]!=-2) return dp[curr][target];
        int inc = rec(nums,curr+1,target-nums[curr],dp);
        int exc = rec(nums,curr+1,target,dp);
        if(inc!=-1) inc++;
        return dp[curr][target]=max(inc,exc);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-2));
        return rec(nums,0,target,dp);
    }
    */
   
    /*
    DP

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        // dp[i][j] -> Length of Longest Subsequence ending at i, with sum j
        for(int i=0;i<n;i++){
            dp[i][0] = 0;
        }
        if(nums[0]<=target) dp[0][nums[0]] = 1;
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                if(j<nums[i]){
                    dp[i][j] = dp[i-1][j];
                    continue;
                }
                if(dp[i-1][j-nums[i]]!=-1){
                    dp[i][j]=dp[i-1][j-nums[i]]+1;
                }
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
            }
        }
        return dp[n-1][target];
    }
    */
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prev(target+1,-1);
        vector<int> curr(target+1,-1);
        prev[0] = 0;
        if(nums[0]<=target) prev[nums[0]] = 1;
        for(int i=1;i<n;i++){
            curr[0] = 0;
            for(int j=1;j<=target;j++){
                if(j<nums[i]){
                    curr[j] = prev[j];
                    continue;
                }
                if(prev[j-nums[i]]!=-1){
                    curr[j]=prev[j-nums[i]]+1;
                }
                curr[j] = max(curr[j],prev[j]);
            }
            prev = curr;
        }
        return prev[target];
    }
};