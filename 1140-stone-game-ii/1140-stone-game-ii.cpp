class Solution {
public:
    int dp[101][101][2];
    int helper(vector<int>&piles,int idx,int m,int turn){
        if(idx==piles.size())
            return 0;
        if(dp[idx][m][turn]!=-1)
            return dp[idx][m][turn];
        
        if(turn){
            
            int sum=0;
            int val=0;
            int ans=0;
            for(int i=idx;i<idx+2*m;i++){
                if(i==piles.size())
                    break;
                val++;
                sum+=piles[i];
                ans=max(ans,sum+helper(piles,i+1,max(val,m),turn^1));
            }
               return dp[idx][m][turn]= ans;
            
            }
        
        else{
            int ans=INT_MAX;
            int val=0;
            for(int i=idx;i<idx+2*m;i++)
            {
                if(i==piles.size())
                    break;
                val++;
                ans=min(ans,helper(piles,i+1,max(val,m),turn^1));
            }
                return dp[idx][m][turn]=ans;
                
            }
    }
    
    
    
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int ans=helper(piles,0,1,1);
        return ans;
        
    }
};