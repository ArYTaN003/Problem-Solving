int findMin(vector<int>& nums) {
        int l=0,u=nums.size()-1,mid;
        while(l<u){
            // Go towards the side which is less
            mid=l+(u-l)/2;
            if(nums[mid]<nums[u]){

                u=mid;
            }
            else{
                l=mid+1;
            }
        }
        return nums[l];
    }