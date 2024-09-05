class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int msum=0;
        int m=rolls.size();
        for(int i=0;i<rolls.size();i++){
            msum+=rolls[i];
        }
        int nsum=(mean*(m+n))-msum;
        if(nsum<n || nsum>6*n)
            return {};
        int rem=nsum%n;
         vector<int>ans(n,nsum/n);
        for(int i=0;i<rem;i++)
            ans[i]+=1;
        return ans;
        
        
    }
};