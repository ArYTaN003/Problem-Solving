class Solution {
public:
    TreeNode* sortedArrayToBST1(vector<int>& nums,int l,int r) {
        if(l>r) return NULL;
        int mid=l+(r-l)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=sortedArrayToBST1(nums,l,mid-1);
        root->right=sortedArrayToBST1(nums,mid+1,r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST1(nums,0,nums.size()-1);
    }
};