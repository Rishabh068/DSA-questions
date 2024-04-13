class Solution {
public:
    int dp[1001][201];
    int helper(vector<int>& nums,int idx, int target){
        if(idx==nums.size())
            return 0;
        if(target<0)
            return 0;
        if(target==0)
            return 1;
        if(dp[target][idx]!=-1)
            return dp[target][idx];
        int option1=helper(nums,0,target-nums[idx]);
        int option2=helper(nums,idx+1,target);
        return dp[target][idx]=option1+option2;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int ans=helper(nums,0,target);
        return ans;
        
    }
};