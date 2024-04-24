class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int ary = 0;
        int n = colors.length();
        vector<vector<int>> adj(n,vector<int>());
        vector<int> indegree(n,0);
        vector<vector<int>> color_freq(n,vector<int>(26,0));
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int f;
        while(!q.empty()){
            f = q.front();
            q.pop();
            color_freq[f][colors[f]-'a']++;
            ary = max(ary,color_freq[f][colors[f]-'a']);
            n--;
            for(int v:adj[f]){
                for(int i=0;i<26;i++){
                    color_freq[v][i] = max(color_freq[v][i],color_freq[f][i]);
                }
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }

        }
        return n==0?ary:-1;
    }
};