bool helper(TreeNode* root,int B,vector<int>&path){
    if(root==NULL) return false;
    if(root->val==B){
        path.push_back(root->val);
        return true;
    }
    else if(helper(root->left,B,path) || helper(root->right,B,path)){
        path.push_back(root->val);
        return true;
    }
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> path;
    helper(A,B,path); 
    reverse(path.begin(),path.end());  
    return path; 
}