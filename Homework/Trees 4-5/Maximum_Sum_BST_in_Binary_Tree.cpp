class Solution {
    class Helper{
        public:
        int maxi;
        int mini;
        int sum;
        bool isBST;
    };
public:
    Helper maxSum(TreeNode* root,int &maxsum){
        Helper ary;
        if(root==NULL){
            ary.maxi = INT_MIN;
            ary.mini = INT_MAX;
            ary.sum = 0;
            ary.isBST = true;
            return ary;
        }
        Helper l = maxSum(root->left,maxsum);
        Helper r = maxSum(root->right,maxsum);
        ary.isBST = false;
        ary.sum = 0;
        if(l.isBST && r.isBST && root->val<r.mini && root->val>l.maxi){
            ary.sum = l.sum+r.sum+root->val;
            ary.isBST = true;
        }
        maxsum = max(ary.sum,maxsum);
        ary.maxi = max(root->val,r.maxi);
        ary.mini = min(root->val,l.mini);
        return ary;
    }
    int maxSumBST(TreeNode* root) {
        if(root==NULL) return 0;
        int maxsum = 0;
        maxSum(root,maxsum);
        return maxsum;
    }
};