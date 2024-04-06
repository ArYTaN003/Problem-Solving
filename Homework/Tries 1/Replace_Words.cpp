class Node{
    Node* child[26];
    bool isEnd;
    public:
    Node(){
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        isEnd = false;
    }
    void insert(string word){
        Node* p =this;
        int n = word.length();
        for(int i=0;i<n;i++){
            if(p->child[word[i]-'a']==NULL){
                p->child[word[i]-'a'] = new Node();
            }
            p = p->child[word[i]-'a'];
        }
        p->isEnd = true;
    }
    string get_root(string word){
        Node* p =this;
        int n = word.length();
        for(int i=0;i<n;i++){
            if(p->isEnd) return word.substr(0,i); 
            if(p->child[word[i]-'a']==NULL){
                break;
            }
            p = p->child[word[i]-'a'];
        }
        return "#";
    }
};
class Solution {
    Node* root;
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ary = "";
        root = new Node();
        int n = dictionary.size();
        for(int i=0;i<n;i++){
            root->insert(dictionary[i]);
        }
        int m = sentence.length();
        string r;
        for(int i=0;i<m;i++){
            int j = i+1;
            while(j<m && sentence[j]!=' ') j++;
            r = root->get_root(sentence.substr(i,j-i));
            if(r=="#"){
                ary+=sentence.substr(i,j-i)+" ";
            }else{
                ary+=r+" ";
            }
            i=j;
        }
        ary.pop_back();
        return ary;
    }
};