class Solution {
public:
    bool isIsomorphic(string s, string t) {
     unordered_map<char,int>mp1;
     unordered_map<char,int>mp2;
     unordered_map<char,int>mp3;
     unordered_map<char,int>mp4;
        for(int i=0;i<s.length();i++){
            if(mp1.find(s[i])==mp1.end())
                mp1[s[i]]=i;
            if(mp2.find(t[i])==mp2.end())
                mp2[t[i]]=i;
            mp3[s[i]]++;
            mp4[t[i]]++;
            if(!(mp1[s[i]]==mp2[t[i]]&&mp3[s[i]]==mp4[t[i]]))
               return false;
        }
        return true;
        
        
    }
};