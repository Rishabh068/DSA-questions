class Solution {
public:
    int dp[1001][1001];
    int helper(string s,string t,int i,int j){
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]= helper(s,t,i-1,j-1)+helper(s,t,i-1,j);
        }
        else
            return dp[i][j]=helper(s,t,i-1,j);
        
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        int ans= helper(s,t,s.length()-1,t.length()-1);
            return ans;
        
    }
};