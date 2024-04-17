vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int m = grid.size(),n=grid[0].size();
	    queue<pair<int,int>> q;
	    vector<vector<int>> ary(m,vector<int>(n,INT_MAX));
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(grid[i][j]==1){
	                q.push({i,j});
	                ary[i][j] = 0;
	            }
	        }
	    }
	    
	    int dir[8][2] = {{-1,0},{1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
	    int x,y,newx,newy;
	    while(!q.empty()){
	        x = q.front().first;
	        y = q.front().second;
	        q.pop();
            for(int i=0;i<8;i++){
                newx = x+dir[i][0];
                newy = y+dir[i][1];
                if(newx<0 || newy<0 || newx>=m || newy>=n || ary[x][y]+abs(x-newx)+abs(newy-y)>=ary[newx][newy]) continue;
                q.push({newx,newy});
                ary[newx][newy] = ary[x][y]+abs(x-newx)+abs(newy-y);
            }
	    }
	    return ary;
	}