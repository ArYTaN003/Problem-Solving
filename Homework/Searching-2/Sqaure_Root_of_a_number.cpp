int mySqrt(int x) {
        int l=1,u=x,mid,m=0;
        long sq;
        while(l<=u){
            mid=l+(u-l)/2;
            sq=mid*(long)mid;
            if(sq<=x){
                // Square of mid <= x
                // Implies mid is a potential candidate
                // We look for a better answer
                m=mid;
                l=mid+1;
            }else{
                // Square of mid > x , we need to go towards a lower value
                u=mid-1;
            }
        }
        return m;
    }