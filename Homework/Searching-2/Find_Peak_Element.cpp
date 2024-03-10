int findPeakElement(vector<int>& nums) {
        int n=nums.size(),l = 0,u=n-1,mid;
        while(l<=u){
            mid = l+(u-l)/2;
            if(mid-1>=0 && nums[mid]<nums[mid-1]){
                u = mid-1;
            }else if(mid+1<n && nums[mid]<nums[mid+1]){
                l = mid+1;
            }else{
                break;
            }
        }
        return mid;
    }