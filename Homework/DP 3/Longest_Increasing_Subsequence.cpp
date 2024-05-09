class Solution {
public:
    /*
    Recurion/Memoization

    int rec(vector<int>& nums,int curr,int prev,vector<vector<int>>& memo){
        if(curr==nums.size()) return 0; 
        if(prev!=-1 && memo[curr][prev]!=-1) return memo[curr][prev];
        int inc = 0;
        if(prev==-1 || nums[curr]>nums[prev]){
            inc = 1+rec(nums,curr+1,curr,memo);
        }
        int exc = rec(nums,curr+1,prev,memo);
        if(prev!=-1) memo[curr][prev] = max(inc,exc);
        return max(inc,exc);
    }
    */

    /*
    DP
    dp[i] -> Length of Longest Increasing Subsequence ending at i.
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int length_LIS = 1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
            length_LIS = max(length_LIS,dp[i]);
        }
        return length_LIS;
    }    
    */
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>lis.back()){
                // This number can be a part of lis
                lis.push_back(nums[i]);
            }else{
                // We find the next greatest or equal integer from nums[i] and replace it with nums[i] 
                int l = 0,h = lis.size()-1,mid;
                int ind = -1;
                while(l<=h){
                    mid = l+(h-l)/2;
                    if(lis[mid]>=nums[i]){
                        ind = mid;
                        h = mid-1;
                    }else{
                        l = mid+1;
                    }
                }
                lis[ind] = nums[i];
            }
        }
        return lis.size();
    }
};