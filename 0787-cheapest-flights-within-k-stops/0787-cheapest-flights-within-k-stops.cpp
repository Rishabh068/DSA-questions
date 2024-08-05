class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<int>costracker(n,1e8);
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        pq.push({0,{src,0}});
        costracker[src]=0;
        while(!pq.empty()){
            int stops=pq.top().first;
            int node=pq.top().second.first;
            int currcost=pq.top().second.second;
            pq.pop();
            if(stops>k)
                continue;
            for(auto it:adj[node]){
                int child=it.first;
                int childcost=it.second;
                if(childcost+currcost<costracker[child]&&stops<=k){
                    costracker[child]=childcost+currcost;
                    pq.push({stops+1,{child,childcost+currcost}});
                }
                
            }
            
        }
        if(costracker[dst]==1e8)
            return -1;
        
            return costracker[dst];
        
    }
};