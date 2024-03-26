int curr_path_sum(TreeNode* root,int target,long long sum){
        int ans = 0; 
        if(sum+root->val==target) ans++;
        if(root->left) ans+=curr_path_sum(root->left,target,sum+root->val);
        if(root->right) ans+=curr_path_sum(root->right,target,sum+root->val);
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        // Explore Paths in left and right Subtree
        int c = pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
        // Explore all paths from root
        return c+curr_path_sum(root,targetSum,0);
    }