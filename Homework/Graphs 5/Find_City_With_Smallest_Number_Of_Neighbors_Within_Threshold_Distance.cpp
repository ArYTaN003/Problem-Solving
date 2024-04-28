class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        int ans = 0;
        int nodes = INT_MAX;
        for(int i=0;i<n;i++){
            vector<int> distance(n,INT_MAX);
            set<int> st;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,i});
            distance[i] = 0;
            while(!pq.empty()){
                int d = pq.top().first;
                int f = pq.top().second;
                pq.pop();
                st.insert(f);
                for(pair<int,int>& i:adj[f]){
                    if(distance[f]+i.second<=distanceThreshold && distance[f]+i.second<distance[i.first]){
                        distance[i.first] = distance[f]+i.second;
                        pq.push({distance[i.first],i.first});
                    }
                }
            }
            if(st.size()<=nodes){
                nodes = st.size();
                ans = i;
            }
        }
        return ans;
    }