bool hasOnlyOneChild(vector<int>& preorder){
    int n = preorder.size();
    // To check whether each internal node has exactly 1 child , all values on the right of ith node in the preorder ,should
    // either be smaller than ith node,or larger , i.e. all values are either on the right of the ith node or on the left.
    // We can check this using the next descendant and the last descendant(It is also the largest value in the tree) , both should be either larger than ith node or smaller than ith node
    // If last descendant is greater than ith node , it would mean it will be on the right of ith node so, the next descendant has to be greater to satisfy one child condition
    // Otherwise the next descendant will be on the left and the last descendant will be on the right and this will violate our condition
    for(int i=0;i<n-1;i++){
        if((preorder[i]>preorder[i+1] && preorder[i]>preorder[n-1]) || (preorder[i]<preorder[i+1] && preorder[i]<preorder[n-1])){
            continue;
        }else{
            return false;
        }
    }
    return true;
}