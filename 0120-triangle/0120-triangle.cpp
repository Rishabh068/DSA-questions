class Solution {
public:
    int dp[1001][1001];
    int helper(vector<vector<int>>& triangle,int itr,int idx){
        if(itr==triangle.size()-1){
            return triangle[itr][idx];
        }
        if(dp[itr][idx]!=-1)
            return dp[itr][idx];
        int path1=triangle[itr][idx]+helper(triangle,itr+1,idx);
        int path2=triangle[itr][idx]+helper(triangle,itr+1,idx+1);
        return dp[itr][idx]=min(path1,path2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        int ans=helper(triangle,0,0);
        return ans;
        
    }
};