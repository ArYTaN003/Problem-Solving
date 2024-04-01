int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    if(root->data==input){
        return root->data;
    }
    if(root->data>input){
        int ary = findCeil(root->left,input);
        return ary!=-1?min(ary,root->data):root->data;
    }
    return findCeil(root->right,input);
}