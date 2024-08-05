class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<int>timetaken(n+1,1e8);
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       vector<pair<int,int>>adj[n+1];
        
        
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        pq.push({0,k});
        timetaken[k]=0;
        
        
        while(!pq.empty()){
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int child=it.first;
                int ntime=it.second;
                if(time+ntime<timetaken[child]){
                    timetaken[child]=time+ntime;
                    pq.push({time+ntime,child});
                }
            }
        }
       int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(timetaken[i]>ans){
                ans=timetaken[i];
            }
        }
        if(ans==1e8)
            return -1;
        else
            return ans;
        
        
    }
};