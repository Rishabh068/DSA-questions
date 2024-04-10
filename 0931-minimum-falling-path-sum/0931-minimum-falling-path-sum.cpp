class Solution {
public:
    // int dp[2001][2001];
    int helper(vector<vector<int>>& matrix,int itr,int idx,vector<vector<int>>& dp){
        if(itr==matrix.size()-1){
            return matrix[itr][idx];
        }
        if(dp[itr][idx]!=INT_MIN)
            return dp[itr][idx];
        int path1=INT_MAX,path2=INT_MAX,path3=INT_MAX;
        if(idx-1>=0)
            path1=matrix[itr][idx]+helper(matrix,itr+1,idx-1,dp);
        
        path2=matrix[itr][idx]+helper(matrix,itr+1,idx,dp);
        
        if(idx+1<=matrix[0].size()-1)
        path3=matrix[itr][idx]+helper(matrix,itr+1,idx+1,dp);
            
        return dp[itr][idx]=min(path1,min(path2,path3));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // memset(dp,-1,sizeof(dp));
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        
        int ans=INT_MAX;;
        for(int i=0;i<matrix[0].size();i++){
            ans=min(ans,helper(matrix,0,i,dp));
            
        }
       
        return ans;
        
    }
};