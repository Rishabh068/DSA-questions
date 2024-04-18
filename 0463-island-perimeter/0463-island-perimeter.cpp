class Solution {
public:
    int helper(vector<vector<int>>& grid,int n,int m,int i,int j,vector<vector<int>>& visited){
        if(i==n||j==m||i<0||j<0||grid[i][j]==0){
            return 1;
        }
        if(visited[i][j]==1)
            return 0;

        visited[i][j]=1;
        return helper(grid,n,m,i+1,j,visited)+helper(grid,n,m,i,j+1,visited)+helper(grid,n,m,i,j-1,visited)+helper(grid,n,m,i-1,j,visited);
        
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && visited[i][j] == 0)
                    ans=helper(grid,grid.size(),grid[0].size(),i,j,visited);
            }
        }
        return ans;
        
    }
};