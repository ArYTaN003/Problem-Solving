class Trie {
    Trie * child[26];
    bool isEnd;
public:
    Trie() {
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        isEnd = false;
    }
    
    void insert(string word) {
        Trie *p = this;
        int n = word.length();
        for(int i=0;i<n;i++){
            if(p->child[word[i]-'a']==NULL){
                p->child[word[i]-'a'] = new Trie();
            }
            p = p->child[word[i]-'a'];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        Trie *p = this;
        int n = word.length();
        for(int i=0;i<n;i++){
            if(p->child[word[i]-'a']==NULL){
                return false;
            }
            p = p->child[word[i]-'a'];
        }
        return p->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie *p = this;
        int n = prefix.length();
        for(int i=0;i<n;i++){
            if(p->child[prefix[i]-'a']==NULL){
                return false;
            }
            p = p->child[prefix[i]-'a'];
        }
        return true;
    }
};