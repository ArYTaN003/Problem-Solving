class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        unordered_map<int,vector<pair<int,int>>> ary_grid;
        vector<int> ary(n,-1);
        int m = edges.size();
        for(int i=0;i<m;i++){
            ary_grid[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            ary_grid[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> apna_pq;
        apna_pq.push({0,0});
        pair<int,int> f;
        while(!apna_pq.empty()){
            f = apna_pq.top();
            apna_pq.pop();
            if(ary[f.second]!=-1) continue;
            ary[f.second] = f.first;
            for(auto it:ary_grid[f.second]){
                if(it.second+ary[f.second]<disappear[it.first]){
                    apna_pq.push({it.second+ary[f.second],it.first});
                }
            }
        }
        return ary;
    }
};