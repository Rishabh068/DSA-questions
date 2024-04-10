class Solution {
public:
    int dp[500][500];
    int helper(vector<vector<int>>& grid,int x,int y,int n,int m){
        if(x==n-1&&y==m-1)
            return grid[x][y];
        
        if(x<0||x==n||y<0||y==m)
            return 1e5;
        if(dp[x][y]!=-1)
            return dp[x][y];
        int option1=helper(grid,x,y+1,n,m);
        int option2=helper(grid,x+1,y,n,m);
      
        return dp[x][y]= grid[x][y]+ min(option1,option2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        int m=grid[0].size();
        
        int ans=helper(grid,0,0,n,m);
        return ans;
        
    }
};