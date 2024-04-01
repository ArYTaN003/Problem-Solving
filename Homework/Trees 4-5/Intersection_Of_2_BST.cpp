class Solution
{
    public:
    bool search(Node * root,int key){
        if(root==NULL) return false;
        if(root->data==key) return true;
        if(root->data>key){
            return search(root->left,key);
        }
        return search(root->right,key);
    }
    void helper(Node* &root1,Node* root2,vector<int>& common){
        if(root2==NULL) return ;
        helper(root1,root2->left,common);
        if(search(root1,root2->data)){
            common.push_back(root2->data);
        }
        helper(root1,root2->right,common);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
        vector<int> common;
        helper(root1,root2,common);
        return common;
    }
};