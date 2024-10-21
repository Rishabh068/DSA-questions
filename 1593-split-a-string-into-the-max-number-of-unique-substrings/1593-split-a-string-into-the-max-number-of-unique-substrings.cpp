class Solution {
public:
    int ans = 0;
    int max(int a,int b){
        if(a > b)
            return a;
        else
            return b;
    }
    void helper(int i,string& s,map<string,int>& mp){
        if(i == s.size()){
            ans = max(ans,mp.size());
            return;
        }
        string str = "";
        for(int j=i;j<s.size();j++){
            str += s[j];
            mp[str] += 1;
            helper(j+1,s,mp);
            mp[str] -= 1;
            if(mp[str] == 0)
                mp.erase(str);
        }
    }
    int maxUniqueSplit(string s) {
        map<string,int> mp;
        helper(0,s,mp);
        return ans;
    }
};