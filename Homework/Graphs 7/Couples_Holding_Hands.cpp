class DSU{
    vector<int> parent;
    vector<int> rank;
    public:
    DSU(int n,vector<int>& row){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i+=2){
            parent[row[i]] = row[i];
            parent[row[i+1]] = row[i];
            rank[row[i]] = 2;
            rank[row[i+1]] = 2;
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
        //Already part of same table
        if(pi==pj) return false;
        // Need to swap
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
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        DSU dsu(n,row);
        int swaps = 0;
        for(int i=0;i<n;i+=2){
            if(dsu.join(i,i+1)) swaps++;
        }
        return swaps;
    }
};