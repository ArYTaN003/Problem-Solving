#include <bits/stdc++.h>
using namespace std;
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
  	void printSuggestions(string word){
    	Node* p =this;
        int n = word.length();
      string w = "";
        for(int i=0;i<n;i++){
            if(p->child[word[i]-'a']==NULL){
                return ;
            }
          w+=word[i];
            p = p->child[word[i]-'a'];
        }
        suggestion(w,p);
    }
  	void suggestion(string w,Node* p){
    	if(p->isEnd) cout << w << endl;
      for(int i=0;i<26;i++){
      	if(p->child[i]!=NULL){
          	w+=('a'+i);
        	suggestion(w,p->child[i]);
          w.pop_back();
        }
      }
    }
};
int main()
{
	Node* root = new Node();
	root->insert("hello");
	root->insert( "dog");
	root->insert("hell");
	root->insert("cat");
	root->insert( "a");
	root->insert( "hel");
	root->insert("help");
	root->insert( "helps");
	root->insert("helping");
	root->printSuggestions("hel");
	return 0;
}