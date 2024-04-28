class Solution {
public:
    int dp[3000][3000];
    int helper(string &text1,string &text2,int idx1,int idx2,int n,int m){
        if(idx1==n||idx2==m)
            return 0;
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        
        if(text1[idx1]==text2[idx2])
            return dp[idx1][idx2]= 1+helper(text1,text2,idx1+1,idx2+1,n,m);
        
        return dp[idx1][idx2]= 0+max(helper(text1,text2,idx1+1,idx2,n,m),helper(text1,text2,idx1,idx2+1,n,m));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        int n=text1.length(),m=text2.length();
        int ans=helper(text1,text2,0,0,n,m);
        return ans;
        
    }
};