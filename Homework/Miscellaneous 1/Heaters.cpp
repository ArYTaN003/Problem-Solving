class Solution {
    bool isPossible(vector<int>& houses,vector<int>& heaters,int& rad,int& m,int& n){
        int j = 0;
        for(int i=0;i<m;i++){
            while(j<n && abs(houses[i]-heaters[j])>rad){
                j++;
            }
            if(j==n) return false;
        }
        return true;
    }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // Search Space -> [0,Max Possible Radius]
        // Condition -> If it is possible to warm each house using mid radius , means for all
        // value >mid , it is possible to warm the houses so mid is a possible candidate ,and
        // we look for a smaller value , otherwise if its not possible we look for a 
        // larger value
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int n = heaters.size(),m=houses.size();
        int l = 0,h=max(abs(heaters[n-1]-houses[0]),abs(heaters[0]-houses[m-1])),mid,ans;
        while(l<=h){
            mid = l+(h-l)/2;
            if(isPossible(houses,heaters,mid,m,n)){
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};