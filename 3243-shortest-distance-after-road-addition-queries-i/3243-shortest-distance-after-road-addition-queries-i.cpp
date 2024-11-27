class Solution {
public:
    int bfs(map<int,vector<int>>&adj,int n){
        int ans=0;
        queue<int>q;
        vector<int>visited(n,0);
        q.push(0);
        visited[0]=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int node=q.front();
                q.pop();
                if(node==n-1)
                    return ans;
               
                for(auto it:adj[node]){
                    if(visited[it]==0){
                    q.push(it);
                        visited[it]=1;
                    }
                }
               
            }
            ans++;
        }
        return ans;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        map<int,vector<int>>adj;
        vector<int>res;
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        for(int i=0;i<queries.size();i++){
            int from=queries[i][0];
            int to=queries[i][1];
            adj[from].push_back(to);
            res.push_back(bfs(adj,n));
            
        }
        return res;
        
    }
};