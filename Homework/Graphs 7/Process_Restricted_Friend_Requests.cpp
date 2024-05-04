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
    int check_parent(int i){
        int x = parent[i];
        while(parent[x]!=x){
            x= parent[x];
        }
        return x;
    }
    bool join(int i,int j,vector<vector<int>>& restrictions){
        int pi = find_parent(i);
        int pj = find_parent(j);
        // Check for restrictions
        bool valid = true;
        if(rank[pi]<=rank[pj]){
            parent[pi] = pj;
        }else{
            parent[pj] = pi;
        }
        for(auto res:restrictions){
            if(check_parent(res[0])==check_parent(res[1])){
                valid = false;
                break;
            }
        }
        parent[pi] = pi;
        parent[pj] = pj;
        if(!valid){
            return false;
        }
        if(pi==pj) return true;
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
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        int m = requests.size();
        vector<bool> ary(m,false);
        DSU dsu(n);
        for(int i=0;i<m;i++){
            ary[i] = dsu.join(requests[i][0],requests[i][1],restrictions);
        }
        return ary;
    }
};