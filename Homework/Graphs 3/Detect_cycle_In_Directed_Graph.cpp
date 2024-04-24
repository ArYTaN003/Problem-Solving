class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(int j:adj[i]){
                indegree[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        int trav = 0;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            trav++;
            for(int i:adj[f]){
                if(indegree[i]>0){
                    indegree[i]--;
                    if(indegree[i]==0) q.push(i);
                }
            }
        }
        return trav!=V;
    }
};