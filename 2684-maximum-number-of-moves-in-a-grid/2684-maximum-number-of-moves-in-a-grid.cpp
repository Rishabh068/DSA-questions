class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,int m,int n,vector<vector<int>> &grid){
        if(i<0||j<0||i>=m||j>=n)return 0;
        if(dp[i][j] != -1){
           return dp[i][j];
        }
        int a=0,b=0,c=0;
        if(i-1>=0 && j+1<n&&grid[i-1][j+1]>grid[i][j]){
            a = 1+solve(i-1,j+1,m,n,grid);
        }
        if(i+1<m && j+1<n&&grid[i+1][j+1]>grid[i][j]){
            b = 1+solve(i+1,j+1,m,n,grid);
        }
        if(j+1<n&&grid[i][j+1]>grid[i][j]){
            c = 1+solve(i,j+1,m,n,grid);
        }
        return dp[i][j]= max(a,max(b,c));
    }
    int maxMoves(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int ans=INT_MIN;
        for(int i=0;i<grid.size();i++){
            ans=max(ans,solve(i,0,grid.size(),grid[0].size(),grid));
        }
        return ans;
        
        
    }
};;