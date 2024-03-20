bool possible(int a,unordered_map<int,int>& freq,int numboxes){
    int count = 0;
    for(auto f:freq){
        count+=f.second/mid;
    }
    return count>=a;
}
int maxmimumlunchBox(int a,vector<int> &b){
    unordered_map<int,int> freq;
    int max_freq = 0;
    for(int i=0;i<b.size();i++){
        freq[b[i]]++;
        max_freq = max(freq[b[i]],max_freq);
    }
    int l = 0,h = max_freq,ans,mid;
    while(l<=h){
        mid = l+(h-l)/2;
        if(possible(a,freq,mid)){
            ans = mid;
            l = mid+1;
        }else{
            h = mid-1;
        }
    }
    return ans;
}