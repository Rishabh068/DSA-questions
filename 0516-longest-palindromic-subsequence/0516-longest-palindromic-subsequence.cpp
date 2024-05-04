class Solution {
public:
    int dp[1009][1009];
    int helper(string &s1,string &s2,int itr1,int itr2){
        if(itr1==s1.length()||itr2==s2.length())
            return 0;
        if(dp[itr1][itr2]!=-1)
            return dp[itr1][itr2];
        if(s1[itr1]==s2[itr2]){
            return  dp[itr1][itr2]=1+helper(s1,s2,itr1+1,itr2+1);
        }
        else{
            return dp[itr1][itr2]= max(helper(s1,s2,itr1+1,itr2),helper(s1,s2,itr1,itr2+1));
        }
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        string s1=s;
        reverse(s.begin(),s.end());
        cout<<s1<<endl;
        cout<<s<<endl;
        int ans=helper(s1,s,0,0);
        return ans;
        
    }
};