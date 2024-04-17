class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int m = grid.size(),n=grid[0].size();
        int tot = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }else if(grid[i][j]==1){
                    tot++;
                }
            }
        }
        int x,y,t;
        int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
        int ary = 0;
        while(!q.empty()){
            x = q.front().first.first;
            y = q.front().first.second;
            t = q.front().second;
            q.pop();
            if(grid[x][y]==1){
                ary = t;
                tot--;
                grid[x][y] = 2;
            }
            for(int i=0;i<4;i++){
                int newx = x+dir[i][0];
                int newy = y+dir[i][1];
                if(newx<0 || newy<0 || newx>=m || newy>=n || grid[newx][newy]!=1) continue;
                q.push({{newx,newy},t+1});
            }
        }
        return tot!=0?-1:ary;
    }
};