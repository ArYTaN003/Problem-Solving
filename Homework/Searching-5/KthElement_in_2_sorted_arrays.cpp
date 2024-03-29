int kthElement(vector<int> &a, vector<int>& b, int n, int m, int k){
    if(n>m) return kthElement(b,a,m,n,k);
    // If k>n  , then we need to pick atleast k-m elements from first array
    int l = max(0,k-m);
    // At max we can pick k elements
    int h = min(k,n);
    int amid,bmid,aleft,bleft,aright,bright;
    while(l<=h){

       amid = l+(h-l)/2;
        // we take k-amid number of elements from b
       bmid = k-amid;
        aleft = amid==0?INT_MIN:a[amid-1];
         bleft = bmid==0?INT_MIN:b[bmid-1];
         aright = amid==n?INT_MAX:a[amid];
         bright = amid==m?INT_MAX:b[bmid];
         if(aleft<=bright && bleft<=aright){
             // We found a valid Combination and now we simply return the greatest element from the left half 
             // Which will be either aleft or bleft
             return max(aleft,bleft);
         }else if(aleft>bright){
             h = amid-1;
         }else if(bleft>aright){
             l = amid+1;
         }
    }
    return -1;
}