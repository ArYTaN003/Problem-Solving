Node * lca(Node * root,int& a,int& b){
        if(root==NULL || root->data==a || root->data==b) return root;
        Node * l = lca(root->left,a,b);
        Node * r = lca(root->right,a,b);
        if(l!=NULL && r!=NULL) return root;
        else if(l!=NULL) return l;
        else return r;
    }
    bool dist(Node* root,int& a,int& d){
        if(root==NULL) return false;
        if(root->data==a) return true;
        if(dist(root->left,a,d) || dist(root->right,a,d)){
            d++;
            return true;
        }
        return false;
    }
    int findDist(Node* root, int a, int b) {
        Node * lowest_ca = lca(root,a,b);
        int d = 0;
        dist(lowest_ca,a,d);
        dist(lowest_ca,b,d);
        return d;
    }