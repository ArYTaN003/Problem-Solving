class DSU{
    vector<int> parent;
    vector<int> rank;
    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 1;
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
        if(rank[pi]<=rank[pj]){
            parent[pi] = pj;
            rank[pj]+=rank[pi];
        }else{
            parent[pj] = pi;
            rank[pi]+=rank[pj];
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n+1);
        for(auto edge:edges){
            // If edge[0] , edge[1] are already connected , we dont need this edge.
            if(!dsu.join(edge[1],edge[0])) return edge;
        }
        return {};
    }
};