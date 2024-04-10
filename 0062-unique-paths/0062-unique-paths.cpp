class Solution {
public:
    int dp[101][101];
    int helper(int n,int m,int x,int y){
        if(x==n||y==m)
            return 0;
        if(x==n-1&&y==m-1)
            return 1;
        if(dp[x][y]!=-1)
            return dp[x][y];
        int option1=helper(n,m,x+1,y);
        int option2=helper(n,m,x,y+1);
        return dp[x][y]= option1+option2;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        int ans=helper(m,n,0,0);
        return ans;
        
    }
};