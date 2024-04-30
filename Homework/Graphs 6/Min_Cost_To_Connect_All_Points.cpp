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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        int num_nodes = 0;
        int min_cost = 0;
        while(!pq.empty() && num_nodes<n){
            int parent = pq.top().second.second;
            int cost = pq.top().first;
            int current_node = pq.top().second.first;
            pq.pop();
            if(current_node!=parent && !dsu.union_nodes(parent,current_node)){
                continue;
            }            
            min_cost+=cost;
            num_nodes++;
            for(int i=0;i<n;i++){
                if(current_node==i) continue;
                int curr_parent = dsu.find_parent(current_node);
                int i_parent = dsu.find_parent(i);
                if(curr_parent!=i_parent){
                    pq.push({abs(points[current_node][0]-points[i][0])+abs(points[current_node][1]-points[i][1]),{i,current_node}});
                }
            }
        }
        return min_cost;
    }
};