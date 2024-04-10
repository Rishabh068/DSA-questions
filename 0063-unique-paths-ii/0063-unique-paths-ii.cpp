class Solution {
public:
    int dp[101][101];
    int helper(vector<vector<int>>& obstacleGrid,int n,int m,int x,int y){
        if(x<0||y<0||x>=n||y>=m||obstacleGrid[x][y]==1)
            return 0;
        if(x==n-1&&y==m-1)
            return 1;
        if(dp[x][y]!=-1)
            return dp[x][y];

        int option1=helper(obstacleGrid,n,m,x+1,y);
        int option2=helper(obstacleGrid,n,m,x,y+1);
        return dp[x][y]=option1+option2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        if(obstacleGrid[0][0]==1)
            return 0;
       int n=obstacleGrid.size();
       int m=obstacleGrid[0].size();
        int ans=helper(obstacleGrid,n,m,0,0);
        return ans;
        
        
    }
};