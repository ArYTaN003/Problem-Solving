class Solution
{
    public:
    void inorder(Node*root,vector<int>& inord){
        if(root==NULL) return ;
        inorder(root->left,inord);
        inord.push_back(root->data);
        inorder(root->right,inord);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       vector<int> inorder1;
       vector<int> inorder2;
       vector<int> ary;
       inorder(root1,inorder1);
       inorder(root2,inorder2);
       int i=0,j=0;
       while(i<inorder1.size() && j<inorder2.size()){
           if(inorder1[i]<inorder2[j]){
               ary.push_back(inorder1[i++]);
           }else{
               ary.push_back(inorder2[j++]);
           }
       }
       while(i<inorder1.size()){
           ary.push_back(inorder1[i++]);
       }
       while(j<inorder2.size()){
           ary.push_back(inorder2[j++]);
       }
       return ary;
    }
};