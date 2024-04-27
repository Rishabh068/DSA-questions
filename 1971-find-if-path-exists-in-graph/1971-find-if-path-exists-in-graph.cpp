class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        bool ans=false;
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        vector<int>visited(n,0);
        q.push(source);
        visited[source]=1;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(node==destination)
                return true;
            for(auto it:adj[node]){
                if(visited[it]==0){
                    q.push(it);
                    visited[it]=1;
                }
        }
            
        
    }
        return ans; 
    }
};