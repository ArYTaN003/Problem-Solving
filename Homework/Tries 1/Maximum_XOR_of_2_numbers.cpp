class Node{
    Node* child[2];
    public:
    Node(){
        for(int i=0;i<2;i++){
            child[i] = NULL;
        }
    }
    void insert(int num){
        Node* p =this;
        int bit = 0;
        for(int i=31;i>=0;i--){
            bit = (num>>i)&1;
            if(p->child[bit]==NULL){
                p->child[bit] = new Node();
            }
            p = p->child[bit];
        }
    }
    int MaxXor(int num){
        Node * p =this;
        int bit = 0;
        int xo = 0;
        for(int i=31;i>=0 && p!=NULL;i--){
            bit = (num>>i)&1;
            if(p->child[1-bit]!=NULL){
                xo +=(1<<i);
                p = p->child[1-bit];
            }else{
                p = p->child[bit];
            }
        }
        return xo;
    }
};
class Solution {
    Node* root;
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new Node();
        int n = nums.size();
        int ary = 0;
        for(int i=0;i<n;i++){
            ary = max(ary,root->MaxXor(nums[i]));
            root->insert(nums[i]);
        }
        return ary;
    }
};