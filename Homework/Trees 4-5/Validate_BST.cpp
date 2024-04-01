class Solution {
    class Helper{
        public:
        int min;
        int max;
        bool isBST;
    };
public:
    Helper isValid(TreeNode* root){
        Helper ary;
        ary.min = root->val;
        ary.max = root->val;
        ary.isBST = true;
        if(root->left){
            Helper l = isValid(root->left);
            ary.isBST = ary.isBST && l.isBST && root->val>l.max;
            ary.min = min(ary.min,l.min);
        }
        if(root->right){
            Helper r = isValid(root->right);
            ary.isBST = ary.isBST && r.isBST && root->val<r.min;
            ary.max = max(ary.max,r.max);
        }
        return ary;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        return isValid(root).isBST;
    }
};