class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int>mp;
        int i=0,j=0,ans=0;
        while(j<s.size()){
                mp[s[j]]++;
             if(j-i+1==mp.size()){
                ans=max(ans,j-i+1);
            }
            else if(j-i+1>mp.size()){
                while(j-i+1>mp.size()){
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                    mp.erase(s[i]);
                    i++;
                }
            }
            j++;

        }
        return ans;
        
    }
};