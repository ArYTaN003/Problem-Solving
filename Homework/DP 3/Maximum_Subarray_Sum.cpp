class Solution {
public:
    /*
    Recursive

    int rec(vector<int>& nums,int curr,int&max_sum){
        if(curr==nums.size()-1){
            max_sum = max(max_sum,nums[curr]);
            return nums[curr];
        }
        int sum = max(nums[curr],nums[curr]+rec(nums,curr+1,max_sum));
        max_sum = max(max_sum,sum);
        return sum;
    }
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        rec(nums,0,max_sum);
        return max_sum;
    }
    */
    /*
    DP
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        // dp[i] -> max sum of subarray ending at i. 
        dp[0] = nums[0];
        int max_sum = dp[0];
        for(int i=1;i<n;i++){
            dp[i] = max(nums[i],nums[i]+dp[i-1]);
            max_sum = max(dp[i],max_sum);
        }
        return max_sum;
    }
    */
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int max_sum = nums[0];
        for(int i=1;i<n;i++){
            prev = max(nums[i],nums[i]+prev);
            max_sum = max(prev,max_sum);
        }
        return max_sum;
    }
};