class Solution {
public:
    /*
    Recursive/Memoization

    int helper(vector<int>& nums,int curr,int n,vector<int>& dp){
        if(curr>=n) return 0;
        if(dp[curr]!=-1) return dp[curr];
        int inc = nums[curr]+helper(nums,curr+2,n,dp);
        int exc = helper(nums,curr+1,n,dp);
        return dp[curr]=max(inc,exc);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n = nums.size();
        vector<int> dp(n,-1);
        int op1 = helper(nums,0,n-1,dp);
        fill(dp.begin(),dp.end(),-1);
        int op2 = helper(nums,1,n,dp);
        return max(op1,op2);
    }
    */
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n = nums.size();
        vector<int> dp(n,-1);
        // dp[i] -> Max Amount of money we can get at ith index , either excluding it or including it
        dp[0] = nums[0];
        for(int i=1;i<n-1;i++){
            dp[i] = max(dp[i-1],nums[i]+(i-2>=0?dp[i-2]:0));
        }
        int ans = dp[n-2];
        fill(dp.begin(),dp.end(),-1);
        dp[1] = nums[1];
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1],nums[i]+(i-2>=1?dp[i-2]:0));
        }
        ans = max(ans,dp[n-1]);
        return ans;
    }
};