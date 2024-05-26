class Solution {
public:
    const int mod=1e9+7;
    int dp[100001][3][2];
    int helper(int days,int late,int absent){
        if(days==0)
            return 1;
        if(dp[days][late][absent]!=-1)
            return dp[days][late][absent];
        int option1=0,option2=0,option3=0;
        option1=helper(days-1,0,absent)%mod;
        if(late<2)
            option2=helper(days-1,late+1,absent)%mod;
        if(absent==0)
            option3=helper(days-1,0,absent+1)%mod;
        return dp[days][late][absent]= ((option1%mod+option2%mod)%mod+option3%mod)%mod;
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        int ans=helper(n,0,0);
        return ans;
        
    }
};