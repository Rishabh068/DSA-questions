class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
          int n=nums.size();
        int index=-1,maxcount=0;
        vector<int>pre(n,-1);
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(1+dp[j]>dp[i]&&nums[i]%nums[j]==0){
                    dp[i]=dp[j]+1;
                    pre[i]=j;
                }
            }
            if(dp[i]>maxcount){
                index=i;
                maxcount=dp[i];
            }
            
        }
        vector<int>ans;
        while(index!=-1){
            ans.push_back(nums[index]);
            index=pre[index];
        }
      
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};