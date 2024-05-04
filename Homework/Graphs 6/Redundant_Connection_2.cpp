class DSU{
    vector<int> parent;
    public:
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find_parent(int i){
        int x = parent[i];
        while(parent[x]!=x){
            x = parent[x];
        }
        return parent[i]=x;
    }
    bool join(int i,int j){
        int pi = find_parent(i);
        int pj = find_parent(j);
        if(pi==pj) return false;
        parent[pj] = pi;
        return true;
    }
    bool connected(){
        int n = parent.size();
        for(int i=2;i<n;i++){
            if(find_parent(i)!=find_parent(i-1)) return false;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n+1);
        // Given that each node can have exactly one parent , so first find node which
        // has more than 1 parent , we can do that by checking indegree of each node
        // since there is just one extra edge , at max any node can have indegree 2
        vector<int> indegree(n+1,0);
        int in_deg = -1; // Index of node with indegree > 1.
        for(auto edge:edges){
            indegree[edge[1]]++;
            if(indegree[edge[1]]>1) in_deg = edge[1];
        }
        if(in_deg!=-1){
            // we have a node with indegree > 1.
            // so we just need to remove one of the incoming edges  , as one of them is extra
            // to find which edge to remove , we can remove one edge from the graph
            // and check whether we can still connect the graph or not
            // if we are able to connect the graph after removing the edge , that we means
            // the removed edge is extra otherwise the other edge is extra.
            int e1 = -1,e2 = -1;
            for(int i=0;i<n && (e1==-1 || e2==-1);i++){
                if(edges[i][1]==in_deg){
                    if(e1==-1) e1 = i;
                    else e2 = i;
                }
            }
            // cout << e1 << " " << e2 << endl;
            for(int i=0;i<n;i++){
                if(i==e2) continue;
                dsu.join(edges[i][0],edges[i][1]);
            }
            if(dsu.connected()) return edges[e2];
            return edges[e1];  
        }else{
            // This means there is no node with indegree > 1 , so we just check
            // and keep adding edges , once we find an edge that is not required
            // i.e. edge[0] , edge[1] are already connected , we return that edge
            for(int i=0;i<n;i++){
                if(!dsu.join(edges[i][0],edges[i][1])) return edges[i];
            }
            return {};
        }
    }
};