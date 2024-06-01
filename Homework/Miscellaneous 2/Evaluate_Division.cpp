class Solution {
    double find_div(unordered_map<string,unordered_map<string,double>>& mp,string a,string b,unordered_map<string,bool>& visited){
        if(mp[a].count(b)){
            return mp[a][b];
        }
        visited[a] = true;
        for(auto it:mp[a]){
            if(visited[it.first]) continue;
            double temp = find_div(mp,it.first,b,visited);
            if(temp!=-1){
                visited[a] = false;
                mp[a][b] = temp*it.second;
                return mp[a][b];
            }
        }
        visited[a] = false;
        return -1;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> mp;
        int n = equations.size();
        for(int i=0;i<n;i++){
            mp[equations[i][0]][equations[i][1]] = values[i];
            mp[equations[i][1]][equations[i][0]] = 1.0/values[i];
        }
        vector<double> ans;
        unordered_map<string,bool> visited;
        int m = queries.size();
        for(int i=0;i<m;i++){
            if(mp.count(queries[i][0]) && mp.count(queries[i][1])){
                ans.push_back(find_div(mp,queries[i][0],queries[i][1],visited));
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};