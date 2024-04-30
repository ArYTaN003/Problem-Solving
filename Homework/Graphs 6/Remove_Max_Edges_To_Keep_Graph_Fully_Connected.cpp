class DSU{
    vector<int> rank;
    vector<int> parent;
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
    bool union_nodes(int i,int j){
        int i_parent = find_parent(i);
        int j_parent = find_parent(j);
        if(i_parent==j_parent) return false;
        if(rank[i_parent]<rank[j_parent]){
            parent[i_parent] = j_parent;
            rank[j_parent]+=rank[i_parent];
        }else{
            parent[j_parent] = i_parent;
            rank[i_parent]+=rank[j_parent];
        }
        return true;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n+1);
        DSU bob(n+1);
        int edges_req = 0; 
        int m = edges.size();
        int traverse_alice =1,traverse_bob = 1;
        for(int i=0;i<m;i++){
            if(edges[i][0]==3){
                // cout << i << endl;
                if(traverse_alice<n && alice.union_nodes(edges[i][1],edges[i][2])){ 
                    traverse_alice++;
                    edges_req++;   
                }
                if(traverse_bob<n && bob.union_nodes(edges[i][1],edges[i][2])){
                    traverse_bob++;
                }
            }
        }
        for(int i=0;i<m;i++){
            if(traverse_alice<n && edges[i][0]==1 && alice.union_nodes(edges[i][1],edges[i][2])){
                // cout << "ALICE " << i << endl;
                edges_req++;
                traverse_alice++;
            }
            else if(traverse_bob<n && edges[i][0]==2 && bob.union_nodes(edges[i][1],edges[i][2])){
                // cout << "BOB " << i << endl;
                edges_req++;
                traverse_bob++;
            }
        }
        bool alice_source_found = false,bob_source_found = false;
        for(int i=1;i<=n;i++){
            if(alice.find_parent(i)==i){
                if(alice_source_found) return -1;
                alice_source_found = true;
            }
            if(bob.find_parent(i)==i){
                if(bob_source_found) return -1;
                bob_source_found = true;
            }
        }
        return m-edges_req;
    }
};