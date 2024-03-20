int count(int mat[MAX][MAX],int mid,int n){
    
        int i = 0;
        int count = 0;
        int j = n - 1;

        while (i < n && j >= 0) {
            if (mat[i][j] > mid) {
                j--;
            } else {
                count += j + 1;
                i++;
            }
        }
        return count;
}
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
        // Search Space -> [min(mat),max(mat)]
        // Condition -> If at mid , number of elements less than mid are < k , then it means that we need a larger
        // value as , as the kth smallest value will have k elements smaller than it , so we move towards right
        // otherwise , mid could be a potential answer , and we look for a higher value as all values lower than mid will have <k,values smaller than them
        int l = mat[0][0]; 
        int h = mat[n - 1][n - 1]; 
        int mid,ans=0; 
        
        while (l <= h) {
            int mid = l + (h - l) / 2;
            
            if (count(mat,mid,n)> k) {
                h = mid - 1;
            } else {
                ans = mid;
                l = mid+1; 
            }
        }
        return ans; 
}