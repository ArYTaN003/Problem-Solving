class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        int s = rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
        if(root->val>=low &&  root->val <= high){
            return root->val+s;
        }
        return s;
    }
};