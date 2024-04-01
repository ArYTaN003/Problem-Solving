class Solution {
public:
    bool find(TreeNode* root,int k,set<int>& mp){
        if(root==NULL) return false;
        if(mp.find(k-root->val)!=mp.end()){
            return true;
        }
        mp.insert(root->val);
        return find(root->left,k,mp) || find(root->right,k,mp);
    }
    bool findTarget(TreeNode* root, int k) {
        set<int> mp;
        return find(root,k,mp);
    }
};