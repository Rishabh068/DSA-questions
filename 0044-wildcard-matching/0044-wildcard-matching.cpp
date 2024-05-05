class Solution {
public:
    int dp[2001][2001];
    bool helper(string &s,string &p,int i,int j){
        if(i==s.length()&&j==p.length())
            return true;
        if(j==p.length()&&i<s.length())
            return false;
        if(i==s.length()&&j<p.length()){
            for(int i1=j;i1<p.length();i1++){
                if(p[i1]!='*')
                    return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
      
        if(s[i]==p[j]||p[j]=='?')
            return dp[i][j]= helper(s,p,i+1,j+1);
        else if(p[j]=='*'){
            bool option1=helper(s,p,i,j+1);
            bool option2=helper(s,p,i+1,j);
            return dp[i][j]= option1||option2;
        }
            return dp[i][j]= false;
        
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        bool ans=false;
        ans=helper(s,p,0,0);
        return ans;
        
    }
};