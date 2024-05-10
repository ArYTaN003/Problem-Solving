class Solution {
public:
    /*
    Recursive/Memoization

    pair<int,int> rec(vector<int>& nums,int curr,int prev,vector<vector<pair<int,int>>>& dp){
        if(nums.size()==curr){
            return {0,1};
        }
        if(prev!=-1 && dp[curr][prev].first!=-1) return dp[curr][prev];
        int lis = 0,num_lis = 0;
        if(prev==-1 || nums[curr]>nums[prev]){
            pair<int,int> inc = rec(nums,curr+1,curr,dp);
            int l = 1+inc.first;
            if(l>lis){
                lis = l;
                num_lis = inc.second;
            }else if(l==lis){
                num_lis+=inc.second;
            }
        } 
        pair<int,int> exc = rec(nums,curr+1,prev,dp);
        if(exc.first>lis){
            lis = exc.first;
            num_lis = exc.second;
        }else if(exc.first==lis){
            num_lis+=exc.second;
        }
        if(prev!=-1) dp[curr][prev]={lis,num_lis};
        return {lis,num_lis};
    }
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{-1,-1}));
        return rec(nums,0,-1,dp).second;
    }
    */
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        // dp[i] -> LIS ending at index i
        // count[i] -> Number of LIS at ith index
        int lis = 1;
        int num_lis = 1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    if(dp[i]<dp[j]+1){
                        count[i] = count[j];
                        dp[i] = dp[j]+1;
                    }else if(dp[i]==dp[j]+1){
                        count[i]+=count[j];
                    }
                }
            }
            // cout << i << " " << dp[i] << " " << count[i] << endl;
            if(dp[i]>lis){
                lis = dp[i];
                num_lis = count[i];
            }else if(dp[i]==lis){
                num_lis+=count[i];
            }
        }
        // cout << lis << endl;
        return num_lis;
    }
};