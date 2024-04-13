int dfs(unordered_map<int,vector<int>>& adj,int &maxi,int src){
    int longest_path  = 0;
    int second_longest_path = 0;
    for(int i:adj[src]){
        int temp = 1+dfs(adj,maxi,i);
        if(temp>longest_path){
            second_longest_path = longest_path;
            longest_path = temp;
        }else if(temp>second_longest_path){
            second_longest_path = temp;
        }
    }
    maxi = max(maxi,longest_path+second_longest_path);
    return longest_path;
}
int Solution::solve(vector<int> &A) {
    int src = -1;
    int n = A.size();
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<n;i++){
        if(A[i]!=-1) adj[A[i]].push_back(i);
        else src = i;
    }
    int maxi = 0;
    dfs(adj,maxi,src);
    return maxi;
}