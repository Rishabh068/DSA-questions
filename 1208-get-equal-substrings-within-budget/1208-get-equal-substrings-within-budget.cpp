class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int currcost=0;
        int i=0,j=0;
        int ans=0;
        while(j<s.length()){
            currcost+=abs(s[j]-t[j]);
            while(currcost>maxCost&&i<=j){
                currcost-=abs(s[i]-t[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
        
    }
};