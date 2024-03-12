bool canPlace(int n,int k,vector<int>& stalls,int minDistance){
        int last = stalls[0];
        int totalCows = 1;
        for(int i=1;i<n && totalCows<k;i++){
            if(stalls[i]-last>=minDistance){
                last = stalls[i];
                totalCows++;
            }
        }
        return totalCows==k;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Search Space -> [1,max(stalls)-min(stalls)]
        // Condition -> We check whether it is possible to place k cows with distance at least mid , if it is possible
        // then mid is a potential candidate , and we check for a higher value, otherwise we check for a lower value
        sort(stalls.begin(),stalls.end());
        int l = 1,h=stalls[n-1]-stalls[0],mid,ans=1;
        while(l<=h){
            mid = l+(h-l)/2;
            if(canPlace(n,k,stalls,mid)){
                ans = mid;
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return ans;
    }