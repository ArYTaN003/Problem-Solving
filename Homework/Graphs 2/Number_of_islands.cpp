class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j){
       grid[i][j] = '0';
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int p=0;p<4;p++){
            int new_i=i+dx[p];
            int new_j=j+dy[p];
            if(new_i<0 || new_i>=grid.size() || new_j<0 || new_j>=grid[0].size()){
                continue;
            }
             if(grid[new_i][new_j]=='1'){
                    dfs(grid,new_i,new_j);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ary = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ary++;
                }
            }
        }
        return ary;
    }
};