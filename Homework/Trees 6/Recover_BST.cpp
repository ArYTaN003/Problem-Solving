class Solution {
public:
    void helper(TreeNode* root,TreeNode*&prev,TreeNode*& ele1,TreeNode*&ele2){
        if(root==NULL) return ;
        helper(root->left,prev,ele1,ele2);
        // Now we check the value of prev with root
        if(prev){
            if(ele1==NULL && prev->val>root->val){
                // Case where we have not found any pair of elements 
                // We check whether the prev node is larger than current
                // As we are traversing a BST in inorder so it should be in sorted order i.e. prev->val<root-val
                // But if this condition is not satisfied it means that root and prev are a possible pair of elements 
                // That we need to correct
                ele1 = prev;
                ele2 = root;
            }else if(prev->val>root->val){
                // More than 1 pair 
                ele2 = root;
            }
        }
        prev = root;
        helper(root->right,prev,ele1,ele2);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* prev=NULL;
        TreeNode* ele1 = NULL;
        TreeNode* ele2 = NULL;
        helper(root,prev,ele1,ele2);
        swap(ele1->val,ele2->val);
    }
};