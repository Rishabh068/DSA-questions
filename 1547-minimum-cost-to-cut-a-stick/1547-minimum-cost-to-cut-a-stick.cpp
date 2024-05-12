class Solution {
public:
    int dp[105][105];
    int helper(vector<int>& cuts,int i,int j){
       if(i>j)
           return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
       long long int ans=INT_MAX;
        for(int idx=i;idx<=j;idx++){
           long long int mini=cuts[j+1]-cuts[i-1]+helper(cuts,i,idx-1)+helper(cuts,idx+1,j);
            ans=min(ans,mini);
            
        }
        return dp[i][j]= ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
       cuts.push_back(0);
       cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int ans=helper(cuts,1,cuts.size()-2);
        return ans;
            
        
    }
};