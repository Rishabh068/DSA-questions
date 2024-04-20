class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>&visited,int n,int m, int i,int j){
        visited[i][j]=1;
        vector<pair<int,int>>dirs={{-1,0},{1,0},{0,-1},{0,1}};
        for(auto it:dirs){
            int x=it.first;
            int y=it.second;
            int newi=i+x;
            int newj=j+y;
            if(newi<n&&newj<m&&newi>=0&&newj>=0&&grid[newi][newj]=='1'&&visited[newi][newj]==0)
                dfs(grid,visited,n,m,newi,newj);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&visited[i][j]==0){
                    ans++;
                    dfs(grid,visited,n,m,i,j);
                }
            }
        }
        return ans;
        
    }
};