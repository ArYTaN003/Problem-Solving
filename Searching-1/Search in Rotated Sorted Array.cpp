int search(vector<int>& nums, int target) {
        int l=0,u=nums.size()-1,mid;
        while(l<=u){
            mid=l+(u-l)/2;
            if(nums[mid]==target){
                // Target Found
                return mid;
            }
            else if(nums[l]<=nums[mid]){
                // Mid in left array
                if(nums[l]<=target && nums[mid]>target){
                    //Target in left array
                    u=mid-1;
                }
                else{
                    //Target in right array
                    l=mid+1;
                }
            }
            else{
                //Mid in Right array
                if(nums[mid]<target && nums[u]>=target){
                    //Target in right array
                    l=mid+1;
                }
                else{
                    //Target in left array
                    u=mid-1;
                }
            }
        }
        return -1;
    }