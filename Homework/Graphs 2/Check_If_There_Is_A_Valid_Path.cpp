class Solution {
    bool validMove(vector<vector<int>>& grid,int x,int y,char dir){
        if(dir=='#') return true;
        if(grid[x][y]==1){
            return dir=='L' || dir=='R';
        }else if(grid[x][y]==2){
            return dir=='U' || dir=='D';
        }else if(grid[x][y]==3){
            return dir=='R' || dir=='U';
        }else if(grid[x][y]==4){
            return dir=='U' || dir=='L';
        }else if(grid[x][y]==5){
            return dir=='D' || dir=='R';
        }else{
            return dir=='D' || dir=='L';
        }
    }
    bool dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int x,int y,int& m,int& n,char dir){
        if(x<0 || y<0 || x>=m || y>=n || visited[x][y] || !validMove(grid,x,y,dir)) return false;
        if(x==0 && y==0) return true;
        visited[x][y] = true;
        if(grid[x][y]==1){
            return dfs(grid,visited,x,y-1,m,n,'L') || dfs(grid,visited,x,y+1,m,n,'R');
        }else if(grid[x][y]==2){
            return dfs(grid,visited,x-1,y,m,n,'U') || dfs(grid,visited,x+1,y,m,n,'D');
        }else if(grid[x][y]==3){
            return dfs(grid,visited,x+1,y,m,n,'D') || dfs(grid,visited,x,y-1,m,n,'L');
        }else if(grid[x][y]==4){
            return dfs(grid,visited,x+1,y,m,n,'D') || dfs(grid,visited,x,y+1,m,n,'R');
        }else if(grid[x][y]==5){
            return dfs(grid,visited,x-1,y,m,n,'U') || dfs(grid,visited,x,y-1,m,n,'L');
        }else{
            return dfs(grid,visited,x-1,y,m,n,'U') || dfs(grid,visited,x,y+1,m,n,'R');
        }
        visited[x][y] = false;
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        return dfs(grid,visited,m-1,n-1,m,n,'#');
    }
};