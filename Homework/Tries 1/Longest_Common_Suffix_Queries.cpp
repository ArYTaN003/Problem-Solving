class Node{
    Node* child[26];
    int shortestLength;
    int shortestInd;
    public:
    Node(){
        for(int i=0;i<26;i++) child[i] = NULL;
        shortestLength = INT_MAX;
        shortestInd = -1;
    }
    void insert(string a,int ind){
        Node* p = this;
        int n = a.length();
        for(int i=n-1;i>=0;i--){
            if(p->child[a[i]-'a']==NULL){
                p->child[a[i]-'a'] = new Node();
                p->child[a[i]-'a']->shortestLength = n;
                p->child[a[i]-'a']->shortestInd = ind;
            }
            p = p->child[a[i]-'a'];
            if(n<p->shortestLength){
                p->shortestLength = n;
                p->shortestInd = ind;
            }
        }
    }
    int getindex(string &query){
        int n = query.length();
        Node* p = this;
        for(int i=n-1;i>=0;i--){
            if(p->child[query[i]-'a']==NULL) break;
            p = p->child[query[i]-'a'];
        }
        return p->shortestInd;
    }
};
 
class Solution {
    Node* root;
public:
   
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> ary;
        int n = wordsQuery.size(),m=wordsContainer.size(),tan;
        root = new Node();
        int min_index = 0;
        for(int i=0;i<m;i++){
            root->insert(wordsContainer[i],i);
            if(wordsContainer[i].length()<wordsContainer[min_index].length()) min_index = i;
        }
        for(int i=0;i<n;i++){
            tan = root->getindex(wordsQuery[i]);
            if(tan==-1) ary.push_back(min_index);
            else ary.push_back(tan);
        }
        return ary;
    }
};