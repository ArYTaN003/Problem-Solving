bool isPossible(string& s,string&t,int maxCost,int len){
        if(len==0) return true;
        int cost=0,l=0;
        while(l<len){
            cost+=abs(s[l]-t[l]);
            l++;
        }
        if(cost<=maxCost) return true;
        for(;l<s.length();l++){
            cost-=abs(s[l-len]-t[l-len]);
            cost+=abs(s[l]-t[l]);
            if(cost<=maxCost) return true;
        }
        return false;
    }
int equalSubstring(string s, string t, int maxCost) {
        // Using Binary Search
        // Search Space -> length of the string , max answer can be the whole length and min answer can be 0.
        // Condition -> If it is possible to have a string of length mid , with cost<=maxCost then
        // mid is a possible candidate and all the length below mid will satisfy the condition , 
        // so we check for a higher value , otherwise if the cost>maxCost that means the cost will be even higher for all lengths>mid
        // so we check for  a lower value
        // TC -> O(log n)*O(n)
        int l = 0,h = s.length(),mid,ans;
        while(l<=h){
            mid = l+(h-l)/2;
            if(isPossible(s,t,maxCost,mid)){
                ans = mid;
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return ans;
    }