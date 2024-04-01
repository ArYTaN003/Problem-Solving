class Solution {
public:
    int kthSmallest(TreeNode* root, int& k) {
        if(root==NULL) return -1;
        int left = kthSmallest(root->left,k);
        // we found kth element in the left subtree
        if(k==0) return left;
        k--;
        // Root is the kth element
        if(k==0) return root->val;
        // Kth element is in right subtree
        return kthSmallest(root->right,k);
    }
};