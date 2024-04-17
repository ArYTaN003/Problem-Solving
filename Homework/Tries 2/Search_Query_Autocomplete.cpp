class Node{
	Node* child[256];
  	bool isEnd;
  	int freq;
  	public:
  	Node(){
    	for(int i=0;i<256;i++) child[i] = NULL;
      	isEnd = false;
      	freq = 0;
    }
  	void insert(string word,int f){
    	Node* p =this;
        int n = word.length();
        for(int i=0;i<n;i++){
            
            if(p->child[word[i]]==NULL){
                p->child[word[i]] = new Node();
            }
            p = p->child[word[i]];   
        }
      p->isEnd = true;
      p->freq += f;
    }
  	vector<string> suggestions(string word){
    	Node* p =this;
        int n = word.length();
        string w = "";
        for(int i=0;i<n;i++){
            if(p->child[word[i]]==NULL){
                return {};
            }
            w+=word[i];
            p = p->child[word[i]];
        }
        vector<pair<string,int>> ary;
        helper(w,p,ary);
        sort(ary.begin(),ary.end(),[&](pair<string,int>&a,pair<string,int>& b){
            return a.second==b.second?a.first<b.first:a.second>b.second;
        });
        vector<string> tan;
        for(int i=0;i<min((int)ary.size(),3);i++){
            tan.push_back(ary[i].first);
        }
        return tan;
    }
  	void helper(string w,Node* p,vector<pair<string,int>>& ary){
    	if(p->isEnd){
    	   ary.push_back({w,p->freq});   
    	}
      for(int i=0;i<256;i++){
      	if(p->child[i]!=NULL){
          	w+=(char)i;
        	helper(w,p->child[i],ary);
            w.pop_back();
        }
      }
    }
};
class AutoCompleteSystem {
    Node* root;
    string sentence;
public:
 
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        // write code for constructor
        root = new Node();
        int n = sentences.size();
        for(int i=0;i<n;i++){
            root->insert(sentences[i],times[i]);
        }
    }
    vector<string> input(char c) {
        // write code to return the top 3 suggestions when the current character in the stream is c
        // c == '#' means , the current query is complete and you may save the entire query into
        // historical data
        if(c=='#'){
            root->insert(sentence,1);
            sentence = "";
            return {};
        }
        sentence+=c;
        return root->suggestions(sentence);
    }
};