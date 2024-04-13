class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<bool>&visited,int curr,int n){
        visited[curr]=true;
        for(int i=0;i<n;i++){
            if(isConnected[curr][i]==1 && !visited[i]){
                dfs(isConnected,visited,i,n);
            } 
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
       vector<bool> visited(n,false);
       int ary = 0;
       for(int i=0;i<n;i++){
           if(!visited[i]){
               ary++;
               dfs(isConnected,visited,i,n);
           }
       }
       return ary; 
    }
};