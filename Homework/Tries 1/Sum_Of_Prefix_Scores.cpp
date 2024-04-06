class Node{
    Node* child[26];
    int num_words;
    public:
    Node(){
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        num_words = 0;
    }
    void insert(string word){
        Node* p =this;
        int n = word.length();
        for(int i=0;i<n;i++){
            if(p->child[word[i]-'a']==NULL){
                p->child[word[i]-'a'] = new Node();
            }
            p = p->child[word[i]-'a'];
            p->num_words++;
        }
    }
    int get_score(string word){
        Node* p =this;
        int n = word.length();
        int ary = 0;
        for(int i=0;i<n;i++){
            p = p->child[word[i]-'a'];
            ary+=p->num_words;
        }
        return ary;
    }
};
class Solution {
    Node* root;
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        root = new Node();
        int n = words.size();
        for(int i=0;i<n;i++){
            root->insert(words[i]);
        }
        vector<int> ary;
        for(int i=0;i<n;i++){
            ary.push_back(root->get_score(words[i]));
        }
        return ary;
    }
};