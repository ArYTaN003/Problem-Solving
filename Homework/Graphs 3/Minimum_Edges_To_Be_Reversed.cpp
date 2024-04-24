class Solution{
    public:
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            int m = edges.size();
            vector<vector<int>> outgoing(n+1,vector<int>());
            vector<vector<int>> incoming(n+1,vector<int>());
            for(int i=0;i<m;i++){
                outgoing[edges[i][0]].push_back(edges[i][1]);
                incoming[edges[i][1]].push_back(edges[i][0]);
            }
            
            vector<bool> visited(n+1,false);
            deque<pair<int,int>> dq;
            dq.push_front({src,0});
            while(!dq.empty()){
                int node = dq.front().first;
                int rev = dq.front().second;
                dq.pop_front();
                if(node==dst) return rev;
                visited[node] = true;
                for(int v:outgoing[node]){
                    if(!visited[v]){
                        dq.push_front({v,rev});
                    }
                }
                for(int v:incoming[node]){
                    if(!visited[v]){
                        dq.push_back({v,rev+1});
                    }
                }
            }
            return -1;
        }
};