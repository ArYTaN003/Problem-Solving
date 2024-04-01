class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root->val==p->val || root->val==q->val){
            return root;
        }
        if(root->val>p->val && root->val>q->val){
            // Both nodes in left subtree
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val<p->val && root->val<q->val){
            // Both nodes in right subtree
            return lowestCommonAncestor(root->right,p,q);
        }
        else{
            // One node in left subtree , one in right subtree so lca will be root
            return root;
        }
    }
};