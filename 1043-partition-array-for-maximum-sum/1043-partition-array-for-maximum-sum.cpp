class Solution {
public:
    int dp[501];
    int helper(vector<int>&arr,int k,int idx){
        if(idx==arr.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int cnt=0;
        int ans=0;
        int maxuntil=INT_MIN;
        for(int i=idx;cnt<k&&i<arr.size();i++){
            maxuntil=max(maxuntil,arr[i]);
            ans=max(ans,(i-idx+1)*maxuntil+helper(arr,k,i+1));
            cnt++;
        }
        return dp[idx]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        int ans=helper(arr,k,0);
        return ans;
        
    }
};