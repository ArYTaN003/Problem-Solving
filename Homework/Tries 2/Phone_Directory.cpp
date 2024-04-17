class Node{
	Node* child[26];
  	bool isEnd;
  	public:
  	Node(){
    	for(int i=0;i<26;i++) child[i] = NULL;
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
  	vector<string> suggestions(string word){
    	Node* p =this;
        int n = word.length();
        string w = "";
        for(int i=0;i<n;i++){
            if(p->child[word[i]-'a']==NULL){
                return {"0"};
            }
            w+=word[i];
            p = p->child[word[i]-'a'];
        }
        vector<string> ary;
        helper(w,p,ary);
        if(ary.size()==0) ary.push_back("0");
        return ary;
    }
  	void helper(string w,Node* p,vector<string>& ary){
    	if(p->isEnd){
    	    ary.push_back(w);
    	}
      for(int i=0;i<26;i++){
      	if(p->child[i]!=NULL){
          	w+=('a'+i);
        	helper(w,p->child[i],ary);
            w.pop_back();
        }
      }
    }
};
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>> ary;
        Node* root = new Node();
        for(int i=0;i<n;i++){
            root->insert(contact[i]);
        }
        int l = s.length();
        for(int i=0;i<l;i++){
            ary.push_back(root->suggestions(s.substr(0,i+1)));
        }
        return ary;
    }
};