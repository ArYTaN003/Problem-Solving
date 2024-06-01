class Solution {
public:
    int totalFruit(vector<int>& nums) {
        // Basically we need to find the max length of subarray that contains at most 2 distinct elements
        int n = nums.size();
        int i=0;
        int f1=-1,f2=-1;
        int f1_freq = 0,f2_freq = 0;
        int j=0;
        while(j<n && (f1==-1 || f2==-1)){
            if(f1==-1){
                f1 = nums[j];
                f1_freq = 1;
            }
            else if(f1!=nums[j]){ 
                f2 = nums[j];
                f2_freq = 1;
            }else{
                f1_freq++;
            }
            j++;
        }
        int max_length = j-i;
        for(;j<n;j++){
            if(nums[j]==f1 || nums[j]==f2){
                if(nums[j]==f1) f1_freq++;
                if(nums[j]==f2) f2_freq++;
                max_length = max(max_length,j-i+1);
                continue;
            }
            while(i<j && f1_freq!=0 && f2_freq!=0){
                if(nums[i]==f1) f1_freq--;
                if(nums[i]==f2) f2_freq--;
                i++;
            }
            if(f1_freq==0){
                f1 = f2;
                f1_freq = f2_freq;
            }
            f2 = nums[j];
            f2_freq = 1;
            max_length = max(max_length,j-i+1);
            
        }
        return max_length;
    }
};