int kthElement(vector<int> &a, vector<int>& b, int n, int m, int k){
    int l = max(0,k-m);
    int h = min(k,n);
    int amid,bmid,aleft,bleft,aright,bright;
    while(l<=h){
       amid = l+(h-l)/2;
       bmid = k-amid;
        aleft = amid==0?INT_MIN:a[amid-1];
         bleft = bmid==0?INT_MIN:b[bmid-1];
         aright = amid==n?INT_MAX:a[amid];
         bright = amid==m?INT_MAX:b[bmid];
         if(aleft<=bright && bleft<=aright){
             return max(aleft,bleft);
         }else if(aleft>bright){
             h = amid-1;
         }else if(bleft>aright){
             l = amid+1;
         }
    }
    return -1;
}