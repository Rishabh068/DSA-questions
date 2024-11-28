class Solution {
public:
    vector<pair<int,int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
    int minimumObstacles(vector<vector<int>>& grid) {
        map<pair<int,int>,vector<pair<int,pair<int,int>>>>adj;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>distance(n,vector<int>(m,1e9));
        distance[0][0]=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(auto it:dirs){
                    int newx=i+it.first;
                    int newy=j+it.second;
                    if(newx>=0&&newx<n&&newy>=0&&newy<m){
                        if(grid[newx][newy]==1){
                            adj[{i,j}].push_back({1,make_pair(newx,newy)});
                        }
                        else{
                            adj[{i,j}].push_back({0,make_pair(newx,newy)});
                        }
                    }
                }
                
            }
        }
        pq.push({0,make_pair(0,0)});
        while(!pq.empty()){
            auto node=pq.top();
            int dist=node.first;
            int x=node.second.first;
            int y=node.second.second;
            pq.pop();
            for(auto it:adj[{x,y}]){
                int childdist=it.first;
                int childx=it.second.first;
                int childy=it.second.second;
                if(dist+childdist<distance[childx][childy]){
                    distance[childx][childy]=dist+childdist;
                    pq.push({dist+childdist,make_pair(childx,childy)});
                }
            
            }
            
        }
        return distance[n-1][m-1];
        
    }
};