 bool isPossible(vector<int>& bloomDay,int& k,int days,int& m){
        int n = bloomDay.size();
        int bouquets = 0,r,i=0;
        bool check = true;
        while(i<n){
            r = i;
            check = true;
            while(r<n && r<i+k){
                if(bloomDay[r]>days){
                    check = false;
                    break;
                }
                r++;
            }
            if(r-i==k && check){
                bouquets++;
                i = i+k;
            }else{
                i = r+1;
            }
        }
        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // Search Space -> [min(bloomDay),max(bloomDay)] , the max days after which all the flowers will definitely bloom is max(bloomDay)
        // and the min days after which the flowers could bloom is min(bloomDays)
        // Condition -> if it is possible for atleast m bouquets to be made in mid number of days , that means mid is a potential answer
        // and we need to look for a lower value , otherwise it is not possible to have atleast m bouquets in mid days , so we look for a larger value  
        int temp,l = *min_element(bloomDay.begin(),bloomDay.end()),h=*max_element(bloomDay.begin(),bloomDay.end()),mid,ans=-1;
        while(l<=h){
            mid = l+(h-l)/2;
            // cout << mid << " " << temp << endl;
            if(isPossible(bloomDay,k,mid,m)){
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }