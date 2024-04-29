class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<bool> ans(m,false); // ans[i] -> Whether ith edge is a part of shortest path or not
        vector<vector<pair<int,int>>> adj(n);//Ajacency List
        map<pair<int,int>,int> mp;// Map from edge to index         
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
            mp[{edges[i][0],edges[i][1]}] = i;
            mp[{edges[i][1],edges[i][0]}] = i;
        }
        vector<vector<int>> parent(n);// Stores the parent of ith node in shortest path
        // in case of multiple shortest paths stores multiple parents 
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        // Initially we are at 0.
        pq.push({0,{0,0}});
        vector<int> distance(n,INT_MAX);
        distance[0] = 0;
        while(!pq.empty()){
            int f = pq.top().second.first;
            int p = pq.top().second.second;
            int d = pq.top().first;
            pq.pop();
            // if we are at n-1 node we dont need to add the adjacency of n-1 as it is our destination 
            if(f==n-1) continue;
            for(auto& it:adj[f]){
                if(distance[f]+it.second<distance[it.first]){
                    // If new path is shorter than old path , we update the path for it.first node
                    // And add it to pq
                    parent[it.first] = {};
                    parent[it.first].push_back(f);
                    distance[it.first] = distance[f]+it.second;
                    pq.push({distance[it.first],{it.first,f}});
                }else if(distance[f]+it.second==distance[it.first]){
                    parent[it.first].push_back(f);
                    pq.push({distance[it.first],{it.first,f}});
                }
            }
        }
        // Now , we do BFS traversal from n-1 node and add each parent of the node at front
        // if we have not seen that parent before and also include that edge [p,f] in our ans.
        // This way we only add the edges that are contributing to any shortest path to n-1. 
        queue<int> q;
        vector<bool> visited(n,false);
        q.push(n-1);
        while(!q.empty()){
            int f = q.front();
            q.pop();
            visited[f]=true;
            for(int i:parent[f]){
                ans[mp[{i,f}]] = true;
                if(!visited[i]) q.push(i);
            }
        }
        return ans;
    }
};