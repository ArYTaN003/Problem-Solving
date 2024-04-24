class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n,vector<int>());
        int completed = 0;
        for(auto i:prereq){
            indegree[i[0]]++;
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
       for(int i=0;i<n;i++){
            // we first comlpete the courses that dont have any prereq
            if(indegree[i]==0) q.push(i);
       }
       int f;
       while(!q.empty()){
            f = q.front();
            q.pop();
            // Since the course at front has zero prereq we complete it and increment completed
            completed++;
            // Now we decrement indegree of all adjacent courses to f
            // since there is 1 less prereq for the adjacent courses
            for(int v:adj[f]){
                if(indegree[v]>0){
                    indegree[v]--;
                    if(indegree[v]==0){
                        q.push(v);
                    }
                }
            }
       }
       return completed==n; 
    }
};