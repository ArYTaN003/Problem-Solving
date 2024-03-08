#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,q;
  cin >> n >> q;
  vector<int> height(n);
  for(int i=0;i<n;i++){
    cin >> height[i];
  }
  // cout << endl;
  sort(height.begin(),height.end());
  int query;
  for(int i=0;i<q;i++){
    cin >> query;
    // We use binary Search to find the index of the element that has height>=query
    int l=0,u=n-1,mid;
    int ind = n;
    while(l<=u){
      mid = l+(u-l)/2;
      if(height[mid]>=query){
        // Mid is a possible candidate
        ind = mid;
        // we look futher left
        u = mid-1;
      }else{
        // we go towards right
        l=mid+1;
      }
    }
    cout << n-ind << endl;
  }
  return 0;
}