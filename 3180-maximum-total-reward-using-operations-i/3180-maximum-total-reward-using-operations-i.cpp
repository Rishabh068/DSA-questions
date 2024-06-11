class Solution {
public:
    int dp[2001][4001];
    int helper(vector<int>& rewardValues,int idx,int reward){
        if(idx==rewardValues.size())
            return 0;
        int option1=0,option2=0;
        auto& x=dp[idx][reward];
        if(x!=-1)
            return x;
         option1=helper(rewardValues,idx+1,reward);
        if(reward<rewardValues[idx]){
             option2=rewardValues[idx]+helper(rewardValues,idx+1,reward+rewardValues[idx]);
        }
        return x=max(option1,option2);
        
    }
    int maxTotalReward(vector<int>& rewardValues) {
        memset(dp,-1,sizeof(dp));
        sort(rewardValues.begin(),rewardValues.end());
        return helper(rewardValues,0,0);
        
    }
};