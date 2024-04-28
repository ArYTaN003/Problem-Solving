class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> price(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n);
        for(auto& edge:flights){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        price[src] = 0;
        pq.push({0,{0,src}});
        while(!pq.empty()){
            int stops = pq.top().first;
            int d = pq.top().second.first;
            int f = pq.top().second.second;
            pq.pop();
            // cout << f << " " << d << " " << stops << endl;            
            if(f==dst) continue;
            for(auto& i:adj[f]){
                if(d+i.second<price[i.first] && stops<=k){
                    // cout << i.first<< endl;
                    price[i.first] = d+i.second;
                    pq.push({stops+1,{price[i.first],i.first}}); 
                }
            }
        }
        return price[dst]==INT_MAX?-1:price[dst];
    }
};