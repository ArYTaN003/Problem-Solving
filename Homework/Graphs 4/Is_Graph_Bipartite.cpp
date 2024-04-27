class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int curr,vector<int>& color){
        for(int v:graph[curr]){
            if(color[v]==-1){
                color[v] = !color[curr];
                if(!dfs(graph,v,color)){
                    return false;
                }
            }else if(color[curr]==color[v]){
                return false;
            } 
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i] = 0;
                if(!dfs(graph,i,color)){
                    return false;
                }
            }
        }
        return true;
    }
};