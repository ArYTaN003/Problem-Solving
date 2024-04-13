class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ary;
        // adj[i] -> indegree of ith node
        vector<int> adj(n,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]]++;
        }
        for(int i=0;i<n;i++){
            if(adj[i]==0){
                ary.push_back(i);
            }
        }
        return ary;
    }
};