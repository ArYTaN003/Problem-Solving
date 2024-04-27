class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adj(n+1,vector<int>(n+1,-1));
        vector<int> time(n+1,INT_MAX);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]][times[i][1]]=times[i][2];
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,k});
        time[k]=0;
        while(!q.empty()){
            pair<int,int> f = q.top();
            q.pop();
            for(int i=1;i<=n;i++){
                if(adj[f.second][i]>=0 && time[i]>time[f.second]+adj[f.second][i]){
                    time[i] = time[f.second]+adj[f.second][i];
                    q.push({time[f.second]+adj[f.second][i],i});
                }
            }
        }
        int ans = *max_element(time.begin()+1,time.end());
        return ans==INT_MAX?-1:ans;
    }
};