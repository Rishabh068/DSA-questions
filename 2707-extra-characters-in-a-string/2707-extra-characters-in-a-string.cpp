class Solution {
public:
    int dp[51];
   
    int helper(string s, set<string>&dict,int idx){
        if(idx==s.length())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int ans=INT_MAX;
        string temp="";
        for(int i=idx;i<s.length();i++){
            temp+=s[i];
            if(dict.find(temp)!=dict.end()){
                ans=min(ans, (int)helper(s,dict,i+1));
            }
            else{
                ans=min(ans,(int)temp.length()+helper(s,dict,i+1));
            }

            
        }
        return dp[idx]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp,-1,sizeof(dp));
        set<string>dict;
        for(auto it:dictionary){
            dict.insert(it);
        }
        int ans=helper(s,dict,0);
        return ans;
        
    }
};