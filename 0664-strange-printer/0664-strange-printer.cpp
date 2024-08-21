class Solution {
public:
    int dp[101][101];
    int helper(int l,int r,string s){
        if(l==r)
            return 1;
        if(l>r)
            return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        int i=l+1;
        while(i<=r&&s[i]==s[l]){
            i++;
        }
        if(i==r+1)
            return 1;
        
        int recur=1+helper(i,r,s);
        int greedy=INT_MAX;
        
        for(int j=i;j<=r;j++){
            if(s[j]==s[l]){
                int ans=helper(i,j-1,s)+helper(j,r,s);
                greedy=min(greedy,ans);
            }
        }
        return dp[l][r]= min(greedy,recur);
    }
    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
        int ans=helper(0,s.length()-1,s);
        return ans;
        
    }
};