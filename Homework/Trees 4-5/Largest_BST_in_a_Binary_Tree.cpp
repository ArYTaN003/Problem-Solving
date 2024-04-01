class Solution{
    public:
    class Helper{
        public:
        int maxi;
        int mini;
        int size;
        bool isBST;
    };
    Helper largest(Node*root){
        Helper ary;
        if(root==NULL){
            ary.size=0;
            ary.maxi = INT_MIN;
            ary.mini = INT_MAX;
            ary.isBST  = true;
            return ary;
        }
        Helper l = largest(root->left);
        Helper r = largest(root->right);
        ary.size = max(l.size,r.size);
        ary.isBST = false;
        if(l.isBST && r.isBST && root->data>l.maxi && root->data<r.mini){
            ary.size = l.size+r.size+1;
            ary.isBST = true;
        }
        ary.maxi = max(root->data,r.maxi);
        ary.mini = min(root->data,l.mini);
        return ary;
    }
    int largestBst(Node *root)
    {
    	if(root==NULL) return 0;
    	return largest(root).size;
    }
};