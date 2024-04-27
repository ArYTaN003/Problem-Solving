class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            adj[v1].push_back({v2,succProb[i]});
            adj[v2].push_back({v1,succProb[i]});
        }
        vector<double> distance(n,0.0);
        distance[start]=1.0;
        priority_queue<pair<double,int>> q;
        q.push({1.0,start});
        double ary = 0;
        while(!q.empty()){
            auto curr = q.top();
            q.pop();
            if(curr.second==end){
                ary = max(ary,curr.first);
                continue;
            }
            for(auto i:adj[curr.second]){
                int node = i.first;
                double prob = i.second;
                double nprob = curr.first*prob;
                if(nprob>distance[node]){
                    distance[node] = nprob;
                    q.push({nprob,node});
                }
            }
        }
        return ary;
    }
};