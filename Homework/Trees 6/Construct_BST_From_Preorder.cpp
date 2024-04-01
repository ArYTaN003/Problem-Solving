class Solution {
public:
    TreeNode* bst(vector<int>& preorder,int start,int end){
        if(start>end) return NULL;
        // since its preorder , the order will be NLR , so the value at start will be root
        TreeNode* root = new TreeNode(preorder[start]);
        // Now since its preorder of BST , all values on the left of root will be smaller than the root
        // so we just find the index of the first value > root , in the range [start+1,end]
        // indicating the start of the right subtree
        int i = start+1;
        while(i<=end && preorder[i]<preorder[start]){
            i++;
        }
        root->left = bst(preorder,start+1,i-1);
        root->right= bst(preorder,i,end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bst(preorder,0,preorder.size()-1);
    }
};