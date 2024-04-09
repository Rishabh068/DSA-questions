class Solution {
public:
    int dp[1000];
    int helper(vector<int>& nums,int idx,int end){
        if(idx>=end)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int option1=nums[idx]+helper(nums,idx+2,end);
        int option2=0+helper(nums,idx+1,end);
        return dp[idx]= max(option1,option2);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        if(n==1)
            return nums[0];
        int ans1=helper(nums,0,n-1);
         memset(dp,-1,sizeof(dp));
        int ans2=helper(nums,1,n);
        
         return max(ans1,ans2);
        
    }
};