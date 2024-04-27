class Solution {
public:
    int dp[101][101];
    int helper(string ring,string key,int i,int j,int slength,int klength, map<char,vector<int>>&mp){
        if(j==klength)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = 1e9;
        for(auto it:mp[key[j]]){
            int option1=abs(it-i)+helper(ring,key,it,j+1,slength,klength,mp);
            int option2=slength-abs(it-i)+helper(ring,key,it,j+1,slength,klength,mp);
            ans = min( ans , min(option1,option2)) ;
            
        }
        return dp[i][j]= ans;
       
    }
    int findRotateSteps(string ring, string key) {
        memset(dp,-1,sizeof(dp));
        map<char,vector<int>>mp;
        for(int i=0;i<ring.length();i++){
            mp[ring[i]].push_back(i);
        }
        int ans=helper(ring,key,0,0,ring.length(),key.length(),mp);
        return ans+key.length();
        
    }
};