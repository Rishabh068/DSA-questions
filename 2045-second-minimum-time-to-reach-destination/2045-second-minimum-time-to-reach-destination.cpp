class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto it:edges){
            mp[it[0]].push_back({time,it[1]});
            mp[it[1]].push_back({time,it[0]});
        }
        vector<int>d1(n+1,1e9);
        vector<int>d2(n+1,1e9);
        d1[1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            int timetook=x.first;
            int node=x.second;
            int div=timetook/change;
            if(div%2==1)
            timetook=(div+1)*change;
            
            if(node==n&&d2[node]!=1e9)
                return d2[node];
            
            for(auto it:mp[node]){
                if(timetook+time<d1[it.second]){
                    d2[it.second]=d1[it.second];
                    d1[it.second]=timetook+time;
                    pq.push({timetook+time,it.second});
                }
                else if(timetook+time!=d1[it.second]&&timetook+time<d2[it.second]){
                    d2[it.second]=timetook+time;
                     pq.push({timetook+time,it.second});
                }
            }
        }
        return 0;
        
    }
};