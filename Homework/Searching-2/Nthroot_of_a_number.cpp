int NthRoot(int n, int m)
	{
	    long long l = 1,u = m,mid;
	    long long nthpower;
	    while(l<=u){
	        mid = l+(u-l)/2;
            // using pow(mid,n) goes out of range for higher values of n.
	        nthpower = mid;
            for(int i=1;i<n;i++){
                nthpower *=mid;
                if(nthpower>m) break;
            }
	        if(nthpower==m){
	            return mid;
	        }else if(nthpower>m){
	            u = mid-1;
	        }else{
	            l = mid+1;
	        }
	    }
	    return -1;
	}