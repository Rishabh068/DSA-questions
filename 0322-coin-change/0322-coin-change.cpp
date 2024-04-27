class Solution {
public:
    int dp[10001][12];
    int helper(vector<int>&coins,int amount,int idx){
        if(amount==0)
            return 0;
        if(idx==coins.size())
            return 1e5;
        if(dp[amount][idx]!=-1)
            return dp[amount][idx];
       long long int option1=1e5,option2=1e5;
        option1=helper(coins,amount,idx+1);
        if(amount-coins[idx]>=0)
            option2=1+helper(coins,amount-coins[idx],idx);
        
        return dp[amount][idx]= min(option1,option2);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans=helper(coins,amount,0);
        if(ans>=1e5)
            ans=-1;
        return ans;
        
    }
};