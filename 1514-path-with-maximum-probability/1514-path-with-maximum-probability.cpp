class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<double,int>>>adj;
        adj.clear();
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
             adj[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
       
        priority_queue<pair<double,int>>pq;
        vector<double>probab(n,0);
        probab[start_node]=1.0;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto x=pq.top();
            double probability=x.first;
            int node=x.second;
            pq.pop();
            for(auto it:adj[node]){
               
                if(probability*it.first>probab[it.second]){
                    probab[it.second]=probability*it.first;
                    pq.push({probability*it.first,it.second});
                    // cout<<it.second<<" "<<probab[it.second]
                }
            }
            
        }
        return probab[end_node]; 
        
    }
};