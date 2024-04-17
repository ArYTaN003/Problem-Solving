#include <bits/stdc++.h>
using namespace std;
class Node{
	Node* child[2];
	int count[2];
	public:
	Node(){
		for(int i=0;i<2;i++){
			child[i] = NULL;
			count[i] = 0;
		} 
	}
	void insert(int num){
        Node* p =this;
		int bit = 0;
        for(int i=31;i>=0;i--){
            bit = (num>>i)&1;
            p->count[bit]++;
			if(p->child[bit]==NULL){
                p->child[bit] = new Node();
            }
            p = p->child[bit];
        }
    }
	int subarrLessThanK(int num,int k){
		Node* p = this;
		int ary = 0;
		int bit_k = 0;
		int bit = 0;
		for(int i=31;i>=0 && p!=NULL;i--){
			bit_k = (k>>i)&1;
        	bit = (num>>i)&1;
			if(bit_k==1){
				ary+=p->count[bit];
				p = p->child[1-bit];
			}else{
				p=p->child[bit];
			}
		}
		return ary;
	}
};
long long numOfSubarrLessThanK(vector<int>& arr,int n,int k){
	Node* root = new Node();
	int ary_xor = 0;
	long long ary = 0;
	root->insert(0);
	for(int i=0;i<n;i++){
		ary_xor ^= arr[i];
		ary += root->subarrLessThanK(ary_xor,k);
		root->insert(ary_xor);
	}
	return ary;
}
int main() {
	int t,temp;
	cin >> t;    
	for(int i=0;i<t;i++){
		int n,k;
		vector<int> arr;
		cin >> n >> k;
		for(int i=0;i<n;i++){
			cin >> temp;
			arr.push_back(temp);
		}
		cout << numOfSubarrLessThanK(arr,n,k) << endl;
	}	
	return 0;
}