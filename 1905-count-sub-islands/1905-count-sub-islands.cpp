class Solution {
public:
    vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j,int n,int m,bool &issub,vector<vector<int>>&visited){
        if(i==n||j==m||i<0||j<0)
            return;
        if(grid2[i][j]!=grid1[i][j]){
            issub=false;
        }
        visited[i][j]=1;
        for(auto it:dir){
            int newx=i+it.first;
            int newy=j+it.second;
            if(newx<n&&newy<m&&newx>=0&&newy>=0&&grid2[newx][newy]==1&&!visited[newx][newy])
              dfs(grid1,grid2,newx,newy,n,m,issub,visited);
            
        }
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans=0;
        int n=grid1.size();
        int m=grid1[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1&&!visited[i][j]){
                    bool issub=true;
                    dfs(grid1,grid2,i,j,n,m,issub,visited);
                    if(issub)
                        ans++;
                }
            }
        }
        return ans;
        
        
    }
};