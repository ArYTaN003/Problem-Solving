class Solution
{
  public:
    pair<Node*,Node*> convert(Node* root){
        if(root==NULL) return {NULL,NULL};
        pair<Node*,Node*> left = convert(root->left);
        if(left.second){
            left.second->right = root;
        }
        root->left = left.second;
        pair<Node*,Node*> right = convert(root->right);
        if(right.first){
            right.first->left = root;
        }
        root->right = right.first;
        if(left.first && right.second) return {left.first,right.second};
        else if(left.first) return {left.first,root};
        else if(right.second) return {root,right.second};
        else return {root,root};
    }
    Node *bTreeToCList(Node *root)
    {
    // left -> prev , right->next
    if(root==NULL) return root;
    pair<Node*,Node*> p = convert(root);
    p.first->left =  p.second;
    p.second->right = p.first;
    return p.first;
    }
};