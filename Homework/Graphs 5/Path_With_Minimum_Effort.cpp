class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> effort(n,vector<int>(m,INT_MAX));
        int e,i,j,x,y,h;
        effort[0][0] = 0;
        while(!pq.empty()){
            e = pq.top().first;
            i = pq.top().second.first;
            j = pq.top().second.second;
            pq.pop();
            for(int k=0;k<4;k++){
                x = dir[k][0]+i;
                y = dir[k][1]+j;
                if(x<0 || y<0 || x>=n || y>=m) continue;
                h = max(e,abs(heights[i][j]-heights[x][y]));
                if(h<effort[x][y]){
                    effort[x][y] = h;
                    pq.push({h,{x,y}});
                }
            }
        }
        return effort[n-1][m-1];
    }
};