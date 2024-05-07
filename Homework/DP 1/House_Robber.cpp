class Solution {
public:
    /*
    Recurive/Memoization

    int helper(vector<int>& nums,int curr,vector<int>& dp){
        if(curr>=nums.size()) return 0;
        if(dp[curr]!=-1) return dp[curr];
        int exc = helper(nums,curr+1,dp);
        int inc = nums[curr]+helper(nums,curr+2,dp);
        return dp[curr]=max(inc,exc);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return helper(nums,0,dp);
    }
    */
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        // dp[i] = max amount of money we can get at ith house either by including it or excluding
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            dp[i] = max(dp[i-1],nums[i]+(i-2>=0?dp[i-2]:0));
        }
        return dp[n-1];
    }
}; 