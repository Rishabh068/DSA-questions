class Solution {
public:
    int dp[5001][301];
    int helper(vector<int>& coins,int amount,int idx){
        if(amount==0)
            return 1;
        if(idx==coins.size())
            return 0;
        if(dp[amount][idx]!=-1)
            return dp[amount][idx];
        int option1=0,option2=0;
        if(coins[idx]<=amount){
            option1=helper(coins,amount-coins[idx],idx);
        }
        option2=helper(coins,amount,idx+1);
        return dp[amount][idx]= option1+option2;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        int ans=helper(coins,amount,0);
        return ans;
        
    }
};