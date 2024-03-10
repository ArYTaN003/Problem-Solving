int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size(),l=0,u=n-1,mid;
        while(l<=u){
            mid = l+(u-l)/2;
            if(mid+1<n && nums[mid]==nums[mid+1]){
                // mid is the first occurence
                if(mid&1){
                    // First occurence at odd index
                    // Mid is in right of single element
                    u = mid-1;
                }else{
                    // First occurence at even index
                    // Mid is in left of single element
                    l = mid+1;
                }
            }else if(mid-1>=0 && nums[mid]==nums[mid-1]){
                // mid is the second occurence
                if(mid&1){
                    // First Occurence is at mid-1 , means it will be at even index
                    // Mid is in left of single element
                    l = mid+1;
                }else{
                    //First Occurence is at mid-1 . means it will be at odd index
                    // MId is in right of single element
                    u = mid-1;
                }
            }else{
                // Element at mid is not equal to neither mid-1 nor mid+1 
                // This is the single element
                break;
            }
        }
        return nums[mid];
    }