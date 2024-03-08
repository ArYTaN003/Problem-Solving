#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,q;
  cin >> n >> q;
  vector<int> arr(n);
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  sort(arr.begin(),arr.end());
  int query;
  for(int i=0;i<q;i++){
    cin >> query;
    // We use binary Search to find the index of the element that has height>=query
    int l=0,u=n-1,mid;
    int ind = n;
    while(l<=u){
      mid = l+(u-l)/2;
      if(arr[mid]>=query){
        // Mid is a possible candidate
        ind = mid;
        // we look futher left
        u = mid-1;
      }else{
        // we go towards right ,  as there will be no greater elements in the left
        l=mid+1;
      }
    }
    cout << n-ind << endl;
  }
  return 0;
}