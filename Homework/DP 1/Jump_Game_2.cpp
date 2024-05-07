class Solution {
public:
    /*
    Recursive/Memoization

    int helper(vector<int>& nums,int i,int n,vector<int>& dp){
        if(i==nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = INT_MAX;
        for(int j=1;j<=nums[i] && i+j<nums.size();j++){
            int temp = helper(nums,i+j,n,dp);
            if(temp!=INT_MAX) ans = min(ans,1+temp);
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return helper(nums,0,n,dp);
    }
    */
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,INT_MAX);
        // dp[i] -> minimum number of jumps to reach ith index.
        dp[0] = 0;
        for(int i=0;i<n-1;i++){
            for(int j=1;j<=nums[i] && i+j<n;j++){
                dp[i+j] = min(dp[i+j],1+dp[i]);
            }
        }
        return dp[n-1];
    }
};